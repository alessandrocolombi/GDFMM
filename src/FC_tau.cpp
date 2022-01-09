#include "FC_tau.h"
#include <Rcpp.h>
#include <RcppEigen.h>


void FC_tau::update(GS_data& gs_data, const sample::GSL_RNG& gs_engine){
    //Retrive all data needed from gs_data
    const unsigned int& Mna = gs_data.Mstar; // number of unallocated components
    const unsigned int& M = gs_data.M;
    const unsigned int& d = gs_data.d; // number of groups
    const unsigned int& K = gs_data.K; //number of clusters
    std::vector<unsigned int>& n_j= gs_data.n_j; // number of observations per group
    GDFMM_Traits::MatUnsCol& N = gs_data.N; // Matrix of observation oper cluster per group
    std::vector< std::vector<unsigned int>> Ctilde=gs_data.Ctilde; // matrix of partition
    std::vector<unsigned int>& N_k = gs_data.N_k;
    std::vector<std::vector<double>>& data=gs_data.data; //matrix of data we don't copy it since data can be big but we use a pointer
    Partition *p;
    p= gs_data.p;// actual partition of the data
    //Rcpp::Rcout<< p<<std::endl;
    std::vector< std::vector<double>> C=p->C; // C matrix of partition
    //Rcpp::Rcout<< p->name<<std::endl;
    std::vector<unsigned int>& clust_out = p->clust_out; // Vector of clusters
    // RICONTROLLARE E CAPIRE DOVE METTERE CONST
    std::string prior=gs_data.prior; // identifier of the prior adopted for the model togliamo la stringa e mettiamo una classe prior in modo che sia anche più leggibile
    // Initialize ind_i, ind_j
    std::vector<unsigned int> ind_i; // i index of C elements
    std::vector<unsigned int> ind_j;// j index of C elements

    if (prior.compare("normal-inverse-gammaS")) {

        sample::rgamma Gamma;
        sample::rnorm rnorm;

        //NOT allocated tau

        for (int m = K; m < M; ++m){
             double sigma2_na = 1 / Gamma(gs_engine, nu_0/2, (nu_0)*((sigma_0)/2)); // Non allocated Components' variance
             double mu_na = rnorm(gs_engine, mu_0, std::sqrt(sigma2_na / k_0)); // Non allocated Components' mean
             gs_data.mu[m] = mu_na;
             gs_data.sigma[m] = sigma2_na;
        }

        //Allocated tau

        for (unsigned int m = 0; m < K; ++m) {
            std::vector<unsigned int> v;
            for (unsigned int j = 0; j <d ; ++j) {
                Rcpp::Rcout<< "ciao"<<std::endl;

                for (unsigned int i = 0; i < n_j[j] ; ++i) {
                    //Rcpp::Rcout<< Ctilde[j][m];
                    Rcpp::Rcout<< "finoa qua";
                    if(C[j][i] == clust_out[m]){
                        N(j,m)++;
                        ind_i.push_back(i);
                        ind_j.push_back(j);
                        v.push_back(m);

                    }

                }
                Ctilde.push_back(v);
                //Rcpp::Rcout<<N(j,m);
               N_k[m]+=N(j,m);
            }
/*
            //set Ctilde in partition
            double nu_n_clust = nu_0 + N_k[m];
            Rcpp::Rcout<<nu_n_clust;
            double lpk = k_0 + N_k[m];
            Rcpp::Rcout<<lpk;
            double y_bar_clust= mean(ind_i,ind_j,data);
            Rcpp::Rcout<<y_bar_clust;
            double s2_clust= var(y_bar_clust, ind_i, ind_j, data);
            Rcpp::Rcout<<s2_clust;
            //if (is.na(s2_clust[k])){s2_clust[k] <- 0}
            double mu_n_clust = (k_0 * mu_0 + N_k[m] * y_bar_clust) / lpk;
            Rcpp::Rcout<<mu_n_clust;
            double sigma2_n_clust = (nu_0 * (sigma_0 * sigma_0) + (N_k[m] - 1) * s2_clust+ k_0 * N_k[m] * (y_bar_clust - mu_0) * (y_bar_clust - mu_0) / (lpk));
            Rcpp::Rcout<<sigma2_n_clust;
            //Campionamento
            double sigma2_a = 1 / Gamma(gs_engine, nu_n_clust/ 2, sigma2_n_clust / 2);
            double mu_a = rnorm(gs_engine, mu_n_clust, sqrt(sigma2_a / lpk));
            gs_data.mu[m] = mu_a;
            gs_data.sigma[m] = sigma2_a;





*/}
    }
}

// Function to compute the mean of the data (y_mean) for a group
double FC_tau::mean (std::vector<unsigned int> ind_i, std::vector<unsigned int> ind_j,
        const std::vector<std::vector<double>>& data){

    int count = 0;
    double sum = 0.0;
    for (size_t ii = 0; ii<ind_i.size(); ++ii) {
        sum += data.at(ind_j[ii]).at(ind_i[ii]);
        count++;
    }
    return sum/count;
}
// Function to compute the variance of the data
double FC_tau::var(double mean,std::vector<unsigned int> ind_i,std::vector<unsigned int>ind_j,
        const std::vector<std::vector<double>>& data){

    double vari=0.0;
    int count=0;
     for (size_t ii = 0; ii <ind_i.size() ; ++ii) {
         vari += (data.at(ind_j[ii]).at(ind_i[ii]) - mean) *(data.at(ind_j[ii]).at(ind_i[ii]) - mean) ;
         count++;
     }
     return vari/count;
}

// mean e var vanno bene qui e poi si possono chiamare tranquillamente da dentro senza definire il namespace?
