//
// Created by pietr on 12/12/2021.
//
#include "GibbsSampler.h"
#include <Rcpp.h>
#include <RcppEigen.h>


GibbsSampler::GibbsSampler(Eigen::MatrixXd const &data, unsigned int n, unsigned int b_in,
             unsigned int thn, unsigned int seed, Rcpp::List option) : random_engine(seed) {


        // Extract hyper_parameter and initialization values from option

        n_iter = n;
        burn_in = b_in;
        thin = thn;

        unsigned int Mstar0 = Rcpp::as<unsigned int>(option["Mstar0"]);
        double Lambda0 = Rcpp::as<double>(option["Lambda0"]);
        double mu0 = Rcpp::as<double>(option["mu0"]);
        double nu0 = Rcpp::as<double>(option["nu0"]);
        double sigma0 = Rcpp::as<double>(option["sigma0"]);
        double h1 = Rcpp::as<double>(option["Adapt_MH_hyp1"]);
        double h2 = Rcpp::as<double>(option["Adapt_MH_hyp2"]);
        unsigned int pow = Rcpp::as<unsigned int>(option["Adapt_MH_power_lim"]);
        double adapt_var0 = Rcpp::as<double>(option["Adapt_MH_var0"]);
        double k0 = Rcpp::as<double>(option["k0"]);
        double a1 = Rcpp::as<double>(option["alpha_gamma"]);
        double b1 = Rcpp::as<double>(option["beta_gamma"]);
        double a2 = Rcpp::as<double>(option["alpha_lambda"]);
        double b2 = Rcpp::as<double>(option["beta_lambda"]);

        // Initialize gs_data with the correct random seed
        gs_data = GS_data(data, n_iter, burn_in, thin, random_engine, Mstar0, Lambda0, mu0, nu0, sigma0);

        //Initialize Full Conditional Objects
        Partition partition("Partition");
        FC_Mstar Mstar("Mstar");
        FC_gamma gamma("gamma", h1, h2, pow, adapt_var0, a1, b1);
        FC_tau tau("tau", nu0, sigma0, mu0, k0);
        FC_U U("U");
        FC_S S("S");
        FC_Lambda lambda("lambda", a2, b2);

        //Full Conditional vector that we will loop
        std::vector<FullConditional*> fc{&U,
                                         &partition,
                                         &Mstar,
                                         &gamma,
                                         &S,
                                         &tau,
                                         &lambda
                                         };
        FullConditionals = fc;

        //Sample


        for(unsigned int it=0; it<burn_in + n_iter * thin; it++){
        //Loop for updating every fullconditional
        for(FullConditional* full_cond: FullConditionals){
            Rcpp::Rcout<< "Update Step : " << full_cond->name <<std::endl;
            //starting timer to measure updating time
            auto t_start = std::chrono::high_resolution_clock::now();
            full_cond->update(gs_data, random_engine);
            //ending timer to measure updating time
            auto t_end = std::chrono::high_resolution_clock::now();
            //elapsed time in ms
            double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
            Rcpp::Rcout << "It took "<< elapsed_time_ms <<" msecond(s) to update "<< full_cond->name<<std::endl;

            //updating number of iterations necessary for MH algorithm
            gs_data.iterations = it;
        }

        //Printing values of parameter M and K
        Rcpp::Rcout<<"\nValue of M : " << gs_data.M << " - Value of K : " << gs_data.K << "\n"<<std::endl;

        //Store parameters values in out_data struct
        if(it>burn_in && it%thin == 0){
          this->store_params_values();
        }
    }
}

void GibbsSampler::GS_Step() {

//std::cout<<FullConditionals[0]->name<<std::endl;store_params_values()store_params_values()
//FullConditionals[0]->update(gs_data, random_engine);
   //for(FullConditional* full_cond: this->FullConditionals){


   // std::cout<<"update solo partition"<<std::endl;// mettere prima update della partition (da aggiungere anche prima)
    //SI BLOCCA QUI, NON RIESCE A PRENDERE FULL COND
    //partition.update(
    //Rcpp::Rcout<<full_cond->name<<std::endl;



    //full_cond->update(gs_data, random_engine);
    //k=k+1;
   // std::cout<<k<<std::endl;
   //}
}

  //std::cout << gs_data.M << "\n";
  //std::cout << gs_data.K << "\n";


void GibbsSampler::store_params_values() {
  out.K.push_back(gs_data.K);
  out.Mstar.push_back(gs_data.Mstar);
  out.lambda.push_back(gs_data.lambda);
  out.Ctilde.push_back(gs_data.Ctilde);
  out.S.push_back(gs_data.S);
  out.mu.push_back(gs_data.mu);
  out.sigma.push_back(gs_data.sigma);
  out.U.push_back(gs_data.U);
  out.gamma.push_back(gs_data.gamma);
}


out_data GibbsSampler::sample() {
    for(unsigned int it=0; it<burn_in + n_iter * thin; it++){
        this->GS_Step();
        if(it>burn_in && it%thin == 0){
            this->store_params_values();
        }
    }
    return out;
}
