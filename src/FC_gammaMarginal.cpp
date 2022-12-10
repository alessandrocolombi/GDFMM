#include "FC_gammaMarginal.h"
void FC_gammaMarginal::update(GS_data & gs_data, const sample::GSL_RNG & gs_engine){
    // Samplers
    sample::rnorm rnorm;
    sample::runif runif;

    // Data from GS_data
    std::vector<double>& gamma = gs_data.gamma; //gamma variables
    const std::vector<double>& U = gs_data.U; //U latent variables
    const unsigned int & d = gs_data.d; //number of levels
    const double& Lambda = gs_data.lambda; 
    const double& K = gs_data.K; // number of clusters
    const double& iter = gs_data.iterations; //iteration number
    const GDFMM_Traits::MatUnsCol& N = gs_data.N; // dxK matrix; 

    // Auxiliary variables
    // Note: gamma_new_j = exp(log_gamma_new[j])
    std::vector<double> log_gamma_new(d, 1.0); //log of proposed new values for gamma_1, ... , gamma_d. 
    std::vector<double> gamma_new(d, 1.0); //proposed new value for gamma_j
    double ln_acp;    //log of acceptance probability
    double ln_u;      //log of uniform random variable used to decide if accept the move or not
    
    // Variables for Adaptive MH
    double ww_g{ pow(iter + 1,-hyp2) };
    
    // Rcpp::Rcout<<"iter="<<iter<<std::endl;
    /*
    // OLD IMPLEMENTATION THAT IS WRONG!!
    for (unsigned int j = 0; j < d; j++){
        //Rcpp::Rcout<<"Gamma:"<<gamma[j]<<std::endl;
        //Rcpp::Rcout<<"Adaptive variamce var["<<j<<"] = "<<adapt_var_pop_gamma[j]<<std::endl;

        // Update of Gamma via Adapting Metropolis Hastings - computation of quantities is in logarithm for numerical reasons
        
        //1) Sample proposed value in log scale
        log_gamma_new = rnorm(gs_engine, std::log(gamma[j]), std::sqrt(adapt_var_pop_gamma[j]));
        gamma_new = std::exp(log_gamma_new);
        
        //2) Compute acceptance probability in log scale
        ln_acp = log_FCgamma_marginal(gamma_new, Lambda, K, U[j], N.row(j)) - 
                 log_FCgamma_marginal(gamma[j],  Lambda, K, U[j], N.row(j)) +
                 log_gamma_new  - std::log(gamma[j]);

        //3) Acceptance rejection step
        ln_u = std::log(runif(gs_engine));
        
        if (ln_u  < ln_acp)
            gs_data.gamma[j] = gamma_new;

        //std::string update_status = (ln_u  < ln_acp)? " updated" : "NOT updated";
        //Rcpp::Rcout << "gamma_" << j << gs_data.gamma[j] << update_status << std::endl;

        adapt_var_pop_gamma[j] *=  std::exp(  ww_g *( std::exp(std::min(0.0, ln_acp)) - hyp1 
                                                    )  
                                            );

        if (adapt_var_pop_gamma[j] < 1/pow(10, power)){
            adapt_var_pop_gamma[j] = 1/pow(10, power);
        }
        if(adapt_var_pop_gamma[j] > pow(10,power)){
            adapt_var_pop_gamma[j] = pow(10,power);
        }

    }
    */
    if(d == 1){
        //Rcpp::Rcout<<"Gamma:"<<gamma[0]<<std::endl;
        //Rcpp::Rcout<<"Adaptive variamce var["<<0<<"] = "<<adapt_var_pop_gamma[0]<<std::endl;

        // Update of Gamma via Adapting Metropolis Hastings - computation of quantities is in logarithm for numerical reasons
        
        //1) Sample proposed value in log scale
        log_gamma_new[0] = rnorm(gs_engine, std::log(gamma[0]), std::sqrt(adapt_var_pop_gamma[0]));
        gamma_new[0] = std::exp(log_gamma_new[0]);
        
        //2) Compute acceptance probability in log scale
        ln_acp = log_FCgamma_marginal(gamma_new, Lambda, K, U, N ) - 
                 log_FCgamma_marginal(gamma,     Lambda, K, U, N ) +
                 log_gamma_new[0]  - std::log(gamma[0]);

        //3) Acceptance rejection step
        ln_u = std::log(runif(gs_engine));
        
        if (ln_u  < ln_acp)
            gs_data.gamma[0] = gamma_new[0];

        //std::string update_status = (ln_u  < ln_acp)? " updated" : "NOT updated";
        //Rcpp::Rcout << "gamma_" << 0 << gs_data.gamma[0] << update_status << std::endl;

        adapt_var_pop_gamma[0] *=  std::exp(  ww_g *( std::exp(std::min(0.0, ln_acp)) - hyp1 
                                                    )  
                                            );

        if (adapt_var_pop_gamma[0] < 1/pow(10, power)){
            adapt_var_pop_gamma[0] = 1/pow(10, power);
        }
        if(adapt_var_pop_gamma[0] > pow(10,power)){
            adapt_var_pop_gamma[0] = pow(10,power);
        }
    }
    else
        throw std::runtime_error("Error in FC_gammaMarginal: d>1 case not yet implemented ");
}

double FC_gammaMarginal::log_raising_factorial(const unsigned int& n, const double& a) const
{

    if(n==0)
        return 0.0;
    if(a<0)
        throw std::runtime_error("Error in my_log_raising_factorial, can not compute the raising factorial of a negative number in log scale"); 
    else if(a==0.0){
        return -std::numeric_limits<double>::infinity();
    }
    else{
        
        double val_max{std::log(a+n-1)};
        double res{1.0};
        if (n==1)
            return val_max;
        for(std::size_t i = 0; i <= n-2; ++i){
            res += std::log(a + (double)i) / val_max;
        }
        return val_max*res;

    }
}

/*
// OLD FUNCTION THAT IS WRONG
double FC_gammaMarginal::log_FCgamma_marginal(const double& x, const double& Lambda, const unsigned int& K, const double& U_j, const GDFMM_Traits::VecUnsRow& n_jk) const
{   
    const double oneplusU{1.0+U_j};
    const double Lambda_over_oneplusUatx{Lambda/std::pow(oneplusU,x)};
    //sum_{i=1}^K( log_raising_factorial(n_jk[i]), x )
    //const double sumPochammer{ std::accumulate(n_jk.cbegin(), n_jk.cend(), 0.0, [x](const unsigned int& n){return log_raising_factorial(n,x);})   }; //this can be done only from Eigen 3.4
    double sumPochammer{0.0};
    for(std::size_t i = 0; i < n_jk.size(); i++)
        sumPochammer += log_raising_factorial(n_jk[i], x);


    return( Lambda_over_oneplusUatx + 
            std::log( (double)K + Lambda_over_oneplusUatx ) - 
            (double)K * x*std::log(oneplusU) + 
            sumPochammer +
            (alpha - 1.0)*std::log(x) - 
            beta*x    
        );
}
*/

double FC_gammaMarginal::log_FCgamma_marginal(const std::vector<double>& x, const double& Lambda, const unsigned int& K, 
                                              const std::vector<double>& U, const GDFMM_Traits::MatUnsCol& N ) const
{   

    double res{0.0};
    double SumLog = 0.0;

    for(size_t j=0; j<x.size(); j++){

        double gamma_log_onePlusU{x[j]*std::log(U[j] + 1.0)};
        SumLog += gamma_log_onePlusU; 

        //sum_{i=1}^K( log_raising_factorial(N(j,k), x[j] )
        double sumPochammer{0.0};
        for(std::size_t k = 0; k < N.cols(); k++)
            sumPochammer += log_raising_factorial(N(j,k), x[j]);

        res +=  (alpha - 1.0) * std::log(x[j]) - 
                beta * x[j] - 
                (double)K * gamma_log_onePlusU +
                sumPochammer ;
    }
    
    double Lambda_ProdPsi{Lambda*std::exp(-SumLog)};
    return ( res + std::log( (double)K + Lambda_ProdPsi ) + Lambda_ProdPsi );

}