#include "FC_tau_mv.h"
#include <Rcpp.h>
#include <RcppEigen.h>


void FC_tau_mv::update(GS_data& gs_data, const sample::GSL_RNG& gs_engine){

    //Rcpp::Rcout<<"Dentro FC_tau_mv.cpp "<<std::endl;
    //Retrive all data needed from gs_data
    const unsigned int& M = gs_data.M; // number of components
    const unsigned int& d = gs_data.d; // number of groups
    const unsigned int& r= gs_data.r; // number of regression coefficients
    const unsigned int& K = gs_data.K; //number of clusters
    const std::vector<unsigned int>& n_j = gs_data.n_j; // number of observations per group
    const std::vector< std::vector<unsigned int>>& Ctilde = gs_data.Ctilde; // matrix of cluster allocations
    std::vector<std::vector<Individual>>& mv_data = gs_data.mv_data; //matrix of data we don't copy it since data can be big but we use a pointer
    const std::string& prior = gs_data.prior; // identifier of the prior adopted for the model - togliamo la stringa e mettiamo una classe prior in modo che sia anche più leggibile
    const GDFMM_Traits::MatRow& beta = gs_data.beta; // dxr matrix of regression coefficients
    const GDFMM_Traits::vector_uset_uiui& cluster_indicies = gs_data.cluster_indicies; // vector with indicies for each cluster

    // Initialize ind_i, ind_j
    //std::vector<unsigned int> ind_i; // i index of C elements
    //std::vector<unsigned int> ind_j; // j index of C elements


    //Rcpp::Rcout<<"Dentro FC_tau_mv::Update"<<std::endl;
    //Rcpp::Rcout<<"gs_data.Mstar:"<<std::endl<<gs_data.Mstar<<std::endl;
    //Rcpp::Rcout<<"gs_data.M:"<<std::endl<<gs_data.M<<std::endl;
    //Rcpp::Rcout<<"gs_data.K:"<<std::endl<<gs_data.K<<std::endl;
    //Rcpp::Rcout<<"gs_data.mu.size():"<<std::endl<<gs_data.mu.size()<<std::endl;
    //Rcpp::Rcout<<"gs_data.sigma.size():"<<std::endl<<gs_data.sigma.size()<<std::endl;

    if (prior == "Normal-InvGamma") {

        //Initialize tau according to new M

        gs_data.allocate_tau(gs_data.M);

        sample::rgamma Gamma;
        sample::rnorm rnorm;

        //NOT allocated tau

        for (unsigned int m = K; m < M; ++m){
             //Rcpp::Rcout<<"In marginal sampler case, the code should never reach this part"<<std::endl;
             double sigma2_na = 1 / Gamma(gs_engine, nu_0/2, 2/(nu_0 * sigma_0)); // Non allocated Components' variance
             double mu_na = rnorm(gs_engine, mu_0, std::sqrt(sigma2_na / k_0)); // Non allocated Components' mean
             gs_data.mu[m] = mu_na;
             gs_data.sigma[m] = sigma2_na;
             //Rcpp::Rcout << "Non Allocate: mu[" << m << "] = " << mu_na << std::endl;
             //Rcpp::Rcout << "sigma[" << m << "] = " << sigma2_na << std::endl;
        }

        //Allocated tau
        double nu0_post{0.0};
        double k0_post{0.0};
        double mu0_post{0.0};
        double sigma02_post{0.0};
        double sigma2_m{0.0};
        double mu_m{0.0};

        double W{0.0}; // W = 1/(sum(pi)) * sum_{i=1}^{N_m}(pi * Xbari)
        double data_var_term{0.0}; // sum_{i=1}^{N_m}( (pi-1)*Vi )
        double sum_piX2{0.0}; // sum_{i=1}^{N_m}( pi*Xbari^2 )
        unsigned int sum_pi{0}; // sum(pi)

        for (unsigned int m = 0; m < K; ++m){

            /*
                Questo non serve piu
                ind_i.clear();
                ind_j.clear();
                for (unsigned int j = 0; j <d ; ++j) {
                    for (unsigned int i = 0; i < n_j[j] ; ++i) {
                        //Rcpp::Rcout<<"Ctilde["<<j<<"]["<<i<<"]: "<<std::endl<<Ctilde[j][i]<<std::endl;
                        if(Ctilde[j][i] == m){
                            ind_i.push_back(i);
                            ind_j.push_back(j);
                        }
                    }
                }



                Ctilde[0][0]: 0
                Ctilde[0][1]: 0
                Ctilde[1][0]: 0
                Ctilde[1][1]: 1

                Per m = 0 ho,
                Stampo ind_i: 0, 1, 0,
                Stampo ind_j: 0, 0, 1,

                Per m = 1 ho,
                Stampo ind_i: 1,
                Stampo ind_j: 1,

                Immagina Ctilde come una matrice, ind_i e ind_j mi dicono le coordinate che dovrò leggere componente per componente. Infatti nell'esempio,
                data[0,0] - data[0,1] - data[1,0] stanno nel primo cluster e data[1,1] sta nel secondo
            */

            if(r > 0)
                std::tie(W,data_var_term,sum_piX2,sum_pi) = compute_cluster_summaries(cluster_indicies[m],mv_data,beta);
            else
                std::tie(W,data_var_term,sum_piX2,sum_pi) = compute_cluster_summaries(cluster_indicies[m],mv_data);

            //Rcpp::Rcout<<"W:"<<std::endl<<W<<std::endl;
            //Rcpp::Rcout<<"data_var_term:"<<std::endl<<data_var_term<<std::endl;
            //Rcpp::Rcout<<"sum_piX2:"<<std::endl<<sum_piX2<<std::endl;
            //Rcpp::Rcout<<"sum_pi:"<<std::endl<<sum_pi<<std::endl;

            nu0_post = nu_0 + (double)sum_pi;
            k0_post = k_0 + (double)sum_pi;
            mu0_post = (k_0 * mu_0 + (double)sum_pi * W) / k0_post;
            sigma02_post =     1.0/(nu0_post) * (   nu_0*sigma_0 +
                                                    data_var_term +
                                                    sum_piX2 - (double)sum_pi*W*W +
                                                    ( k_0*(double)sum_pi * (mu_0 - W) * (mu_0 - W) ) / (k0_post)
                                                );
            //Rcpp::Rcout<<"nu0_post:"<<std::endl<<nu0_post<<std::endl;
            //Rcpp::Rcout<<"k0_post:"<<std::endl<<k0_post<<std::endl;
            //Rcpp::Rcout<<"mu0_post:"<<std::endl<<mu0_post<<std::endl;
            //Rcpp::Rcout<<"sigma02_post:"<<std::endl<<sigma02_post<<std::endl;
            //Rcpp::Rcout<<"sigma2_m posterior mean = "<< 0.5*(nu0_post*sigma02_post)/( 0.5*nu0_post - 1.0 ) <<std::endl;


            //Campionamento
            sigma2_m = 1.0 / Gamma(gs_engine, nu0_post / 2.0, 2.0 / (nu0_post*sigma02_post) );
                    //sigma2_a = 1.0; // ONLY FOR DEBUGGING
                    //Rcpp::Rcout<<"Update component"<<std::endl;
                    //Rcpp::Rcout<<"Variance related coefficients"<<std::endl;
                    //Rcpp::Rcout<<"s2_clust = "<<std::endl<<s2_clust<<std::endl;
                    //Rcpp::Rcout<<"nu0_post = "<<nu0_post<<std::endl;
                    //Rcpp::Rcout<<"Prior term = "<<nu_0*sigma_0<<std::endl;
                    //Rcpp::Rcout<<"Variance term = "<<(double)N_k[m] - 1.0  * s2_clust<<std::endl;
                    //Rcpp::Rcout<<"squared difference term = "<<( k_0 * (double)N_k[m] * (y_bar_clust - mu_0) * (y_bar_clust - mu_0) ) / (k0_post)<<std::endl;
                    //Rcpp::Rcout<<"Expected value = "<<
                                                        //nu_0*sigma_0/(nu0_post) <<" + "<<  ( (double)N_k[m] - 1.0 ) * s2_clust /nu0_post<< " + " <<
                                                        //( k_0 * (double)N_k[m] * (y_bar_clust - mu_0) * (y_bar_clust - mu_0) ) / (nu0_post*k0_post)<< " = " <<
                                                        //nu0_post*sigma02_post/nu0_post<<std::endl;
                    //Rcpp::Rcout<<"Mean related coefficients"<<std::endl;
                    //Rcpp::Rcout<<"n_k = "<<N_k[m]<<std::endl;
                    //Rcpp::Rcout<<"k_0 = "<<k_0<<std::endl;
                    //Rcpp::Rcout<<"peso 1: n_k/(n_k+k0) = "<< (double)N_k[m] / k0_post <<std::endl;
                    //Rcpp::Rcout<<"peso 2: k0/(n_k+k0) = "<< k_0 / k0_post <<std::endl;
                    //Rcpp::Rcout<<"y_bar_clust:"<<std::endl<<y_bar_clust<<std::endl;
                    //Rcpp::Rcout<<"mu_0:"<<std::endl<<mu_0<<std::endl;
                    //Rcpp::Rcout<<"mu0_post:"<<std::endl<<mu0_post<<std::endl;
            mu_m = rnorm(gs_engine, mu0_post, sqrt(sigma2_m / k0_post));

            gs_data.mu[m] = mu_m;
            gs_data.sigma[m] = sigma2_m;
            //Rcpp::Rcout << "Allocate: mu[" << m << "] = " << mu_m << std::endl;
            //Rcpp::Rcout << "sigma[" << m << "] = " << sigma2_m << std::endl;
        }

        //Rcpp::Rcout<<"Finito update tau"<<std::endl;
        //Rcpp::Rcout<<"Stampo gs_data.mu: ";
        //for(auto __v : gs_data.mu)
            //Rcpp::Rcout<<__v<<", ";
        //Rcpp::Rcout<<std::endl;
//
        //Rcpp::Rcout<<"Stampo gs_data.sigma: ";
        //for(auto __v : gs_data.sigma)
            //Rcpp::Rcout<<__v<<", ";
        //Rcpp::Rcout<<std::endl;
    }
    else if( prior == "Normal"){
        //Rcpp::Rcout<<"Normal prior case"<<std::endl;

                //for (int j = 0; j < Ctilde.size(); j++)
                //{
                    //for (int i = 0; i < Ctilde[j].size(); i++)
                    //{
                        //Rcpp::Rcout<<Ctilde[j][i] + 1<<", ";
                    //}
                    //Rcpp::Rcout<<std::endl;
                //}
        
                //Rcpp::Rcout<<"Stampo gs_data.mu: ";
                //for(auto __v : gs_data.mu)
                    //Rcpp::Rcout<<__v<<", ";
                //Rcpp::Rcout<<std::endl;


        sample::rgamma Gamma;
        sample::rnorm rnorm;

        // Devo estrarre prima mu di sigma perché con M e K che si aggiornano, le dimensioni cambiano e con l'ordine inverso è ingestibile

        //1) The trick is to maintain tau made of mean and variance but this time all variance components will be equal to a single value sigma
        double sigma = gs_data.sigma[0]; //get the old value, this must be done before updating the dimension of the vector
        
        //1.1) Initialize tau according to new M, set all M values for mean equal to 0 and for variance equal to 1
        gs_data.allocate_tau(gs_data.M);

        //1.2) Draw non allocated components
        for (unsigned int m = K; m < M; ++m){

             //Rcpp::Rcout<<"In marginal sampler case, the code should never reach this part"<<std::endl;
             double mu_na = rnorm(gs_engine, mu_0, std::sqrt(sigma / k_0)); // Non allocated Components' mean, use sigma for the variance
             gs_data.mu[m] = mu_na;
             if(gs_data.mu[m] == std::numeric_limits<double>::infinity()){
                 Rcpp::Rcout<<"gs_data.mu["<<m<<"] NON allocato viene infinito"<<std::endl;
                 Rcpp::Rcout<<"mu_0 = "<<mu_0<<std::endl;
                 Rcpp::Rcout<<"std::sqrt(sigma / k_0) = "<<std::sqrt(sigma / k_0)<<std::endl;
             }
             //Rcpp::Rcout << "Non Allocate: mu[" << m << "] = " << mu_na << std::endl;
             //Rcpp::Rcout << "sigma[" << m << "] = " << sigma2_na << std::endl;
        }

        //1.3) Allocated tau
        double k0_post{0.0};
        double mu0_post{0.0};
        double mu_m{0.0};
        
        for (unsigned int m = 0; m < K; ++m){
                /*
                // Questo non serve piu
                // Find data in each cluster
                ind_i.clear();
                ind_j.clear();
                for (unsigned int j = 0; j <d ; ++j) {
                    for (unsigned int i = 0; i < n_j[j] ; ++i) {
                        //Rcpp::Rcout<<"Ctilde["<<j<<"]["<<i<<"]: "<<std::endl<<Ctilde[j][i]<<std::endl;
                        if(Ctilde[j][i] == m){
                            ind_i.push_back(i);
                            ind_j.push_back(j);
                        }
                    }
                }
                */


            double W{0.0}; // W = 1/(sum(pi)) * sum_{i=1}^{N_m}(pi * Xbari)
            double data_var_term{0.0}; // sum_{i=1}^{N_m}( (pi-1)*Vi )
            double sum_piX2{0.0}; // sum_{i=1}^{N_m}( pi*Xbari^2 )
            unsigned int sum_pi{0}; // sum(pi)

            // Here i only need to compute W, but for the moment I keep the old functions that compute everything
            if(r > 0)
                std::tie(W,data_var_term,sum_piX2,sum_pi) = compute_cluster_summaries(cluster_indicies[m],mv_data,beta);
            else
                std::tie(W,data_var_term,sum_piX2,sum_pi) = compute_cluster_summaries(cluster_indicies[m],mv_data);

            k0_post = k_0 + (double)sum_pi;
            mu0_post = (k_0 * mu_0 + (double)sum_pi * W) / k0_post;
            //Rcpp::Rcout<<"k0_post:"<<std::endl<<k0_post<<std::endl;
            //Rcpp::Rcout<<"mu0_post:"<<std::endl<<mu0_post<<std::endl;
            mu_m = rnorm(gs_engine, mu0_post, sqrt(sigma / k0_post));

            gs_data.mu[m] = mu_m;
            
            if(gs_data.mu[m] == std::numeric_limits<double>::infinity()){
                Rcpp::Rcout<<"gs_data.mu["<<m<<"] allocato viene infinito"<<std::endl;
                Rcpp::Rcout<<"k0_post:"<<std::endl<<k0_post<<std::endl;
                Rcpp::Rcout<<"mu0_post:"<<std::endl<<mu0_post<<std::endl;
                Rcpp::Rcout<<"W = "<<W<<std::endl;
                Rcpp::Rcout<<"data_var_term = "<<data_var_term<<std::endl;
                Rcpp::Rcout<<"sum_piX2 = "<<sum_piX2<<std::endl;
                Rcpp::Rcout<<"sum_pi = "<<sum_pi<<std::endl;
            }
            //Rcpp::Rcout << "Allocate: mu[" << m << "] = " << mu_m << std::endl;
            //Rcpp::Rcout << "sigma[" << m << "] = " << sigma2_m << std::endl;
        }

        //2) Then, draw sigma
        
        // First of all, I must know the cluster membership of each data point
        // compute shape - scale posterior parameters
        //Rcpp::Rcout<<"--------------------------------------------"<<std::endl;
        //Rcpp::Rcout<<"M = "<<gs_data.M<<std::endl;
        //Rcpp::Rcout<<"K = "<<gs_data.K<<std::endl;
        //Rcpp::Rcout<<"gs_data.mu.size() = "<<gs_data.mu.size()<<std::endl;
        double scale_post{nu_0 * sigma_0};
        double shape_post{nu_0 + (double)M};
        //double squared_sums{0.0};
        //int counter{0};
        for (unsigned int j = 0; j <d ; ++j) {
            //double ss_j{0.0};
            for (unsigned int i = 0; i < n_j[j] ; ++i) {
                //Rcpp::Rcout<<"j = "<<j<<"; i = "<<i<<std::endl;
                const unsigned int& C_ji = Ctilde[j][i]; //C_ji is the component mixture that defines mean for obseration ji
                Individual& data_ji = mv_data[j][i]; // shortcut, just for notation


                Eigen::Map<GDFMM_Traits::VecCol> eigen_data( &(data_ji.obs_ji[0]), data_ji.n_ji ); //cast observation into eigen form
                GDFMM_Traits::VecCol cl_means( GDFMM_Traits::VecCol::Constant(data_ji.n_ji, gs_data.mu[C_ji]) ); // define a vector where each element is equal to mu_ji
                GDFMM_Traits::VecCol vector_ji( eigen_data - cl_means ); // compute the difference
                if(r > 0){
                    //Rcpp::Rcout<<"***********************************"<<std::endl;
                    //Rcpp::Rcout<<"Qua voglio un vettore di lunghezza "<<data_ji.n_ji<<std::endl;
                    //Rcpp::Rcout<<"data_ji.X_ji.transpose():"<<std::endl<<data_ji.X_ji.transpose()<<std::endl;
                    //Rcpp::Rcout<<"beta.row(j):"<<std::endl<<beta.row(j)<<std::endl;
                    //Rcpp::Rcout<<"data_ji.X_ji.transpose()*beta.row(j):"<<std::endl<<data_ji.X_ji.transpose()*beta.row(j)<<std::endl;
                    //Rcpp::Rcout<<"data_ji.X_ji.transpose()*beta.row(j).transpose():"<<std::endl<<data_ji.X_ji.transpose()*beta.row(j).transpose()<<std::endl;
                    vector_ji -= data_ji.X_ji.transpose()*beta.row(j).transpose();
                    //Rcpp::Rcout<<"vector_ji:"<<std::endl<<vector_ji<<std::endl;
                }
                //Rcpp::Rcout<<"squared term = "<<vector_ji.dot(vector_ji)<<std::endl;
                scale_post += vector_ji.dot(vector_ji);
                shape_post += data_ji.n_ji;
                //squared_sums += vector_ji.dot(vector_ji);
                //ss_j += vector_ji.dot(vector_ji);
                //counter ++;
            }
            //Rcpp::Rcout<<"ss_j = "<<ss_j<<std::endl;
        }
        for (unsigned int m = 0; m < M; ++m){
            scale_post += k_0 * (mu_0 - gs_data.mu[m]) * (mu_0 - gs_data.mu[m]);
        }
        // NOTE: questa parte può essere nettamente migliorata. Shape a posteriori è precomputable e anche il Rate ho fatto dei conti
        // mettendo in luce cosa può essere precomputabile, in modo da dover sommare solo scalari e non vettori
        shape_post /= 2.0;
        scale_post = scale_post/2.0;
        //double sigma_post_mean = scale_post/(shape_post - 1.0);
        //double sigma_post_var  = (sigma_post_mean*sigma_post_mean)/(shape_post - 2.0);
        //Rcpp::Rcout<<"shape_post = "<<shape_post<<std::endl;
        //Rcpp::Rcout<<"scale_post = "<<scale_post<<std::endl;
        //Rcpp::Rcout<<"sigma_post_mean = "<<sigma_post_mean<<std::endl;
        //Rcpp::Rcout<<"sigma_post_var  = "<<sigma_post_var<<std::endl;
        //Rcpp::Rcout<<"squared_sums = "<<squared_sums<<std::endl;
        sigma = 1.0 / Gamma(gs_engine, shape_post, 1.0/scale_post );
        for (unsigned int m = 0; m < M; ++m){
            gs_data.sigma[m] = sigma;
        }
        //Rcpp::Rcout<<"sigma = "<<sigma<<std::endl;
        if(sigma == std::numeric_limits<double>::infinity()){
            Rcpp::Rcout<<"sigma viene infinito"<<std::endl;
            Rcpp::Rcout<<"shape_post = "<<shape_post<<std::endl;
            Rcpp::Rcout<<"scale_post = "<<scale_post<<std::endl;

            Rcpp::Rcout<<"---------------------------"<<std::endl;
            Rcpp::Rcout<<"Rifaccio il conto"<<std::endl;
            Rcpp::Rcout<<"---------------------------"<<std::endl;
            Rcpp::Rcout<<"M = "<<gs_data.M<<std::endl;
            Rcpp::Rcout<<"K = "<<gs_data.K<<std::endl;
            Rcpp::Rcout<<"gs_data.mu.size() = "<<gs_data.mu.size()<<std::endl;
            Rcpp::Rcout<<"Stampo gs_data.mu: ";        
            for(auto __v : gs_data.mu)
                Rcpp::Rcout<<__v<<", ";
            Rcpp::Rcout<<std::endl;

            double scale_post_inf{nu_0 * sigma_0};
            double scale_post2{0.0};
            double shape_post_inf{nu_0 + (double)M};
            double squared_sums{0.0};
            for (unsigned int j = 0; j <d ; ++j) {
                double ss_j{0.0};
                for (unsigned int i = 0; i < n_j[j] ; ++i) {
                    //Rcpp::Rcout<<"j = "<<j<<"; i = "<<i<<std::endl;
                    const unsigned int& C_ji = Ctilde[j][i]; //C_ji is the component mixture that defines mean for obseration ji
                    Individual& data_ji = mv_data[j][i]; // shortcut, just for notation


                    Eigen::Map<GDFMM_Traits::VecCol> eigen_data( &(data_ji.obs_ji[0]), data_ji.n_ji ); //cast observation into eigen form
                    GDFMM_Traits::VecCol cl_means( GDFMM_Traits::VecCol::Constant(data_ji.n_ji, gs_data.mu[C_ji]) ); // define a vector where each element is equal to mu_ji
                    GDFMM_Traits::VecCol vector_ji( eigen_data - cl_means ); // compute the difference
                    //Rcpp::Rcout<<"squared term = "<<vector_ji.dot(vector_ji)<<std::endl;
                    scale_post_inf += vector_ji.dot(vector_ji);
                    shape_post_inf += data_ji.n_ji;
                    squared_sums += vector_ji.dot(vector_ji);
                    ss_j += vector_ji.dot(vector_ji);
                }
                Rcpp::Rcout<<"ss_j = "<<ss_j<<std::endl;
            }
            Rcpp::Rcout<<"Ora calcolo scale_post2"<<std::endl;
            Rcpp::Rcout<<"k_0 = "<<k_0<<std::endl;
            Rcpp::Rcout<<"mu_0 = "<<mu_0<<std::endl;

            for (unsigned int m = 0; m < M; ++m){
                Rcpp::Rcout<<"gs_data.mu["<<m<<"] = "<<gs_data.mu[m]<<std::endl;
                Rcpp::Rcout<<"(mu_0 - gs_data.mu["<<m<<"]) = "<<(mu_0 - gs_data.mu[m])<<std::endl;
                scale_post2 += k_0 * (mu_0 - gs_data.mu[m]) * (mu_0 - gs_data.mu[m]);
            }
            Rcpp::Rcout<<"scale_post2 = "<<scale_post2<<std::endl;
            throw std::runtime_error("FERMO IO - VIENE INFINITO!!! ");
        }

        //Rcpp::Rcout<<"Finito update tau"<<std::endl;
        //Rcpp::Rcout<<"Stampo gs_data.mu: ";
        //for(auto __v : gs_data.mu)
            //Rcpp::Rcout<<__v<<", ";
        //Rcpp::Rcout<<std::endl;

        //Rcpp::Rcout<<"Stampo gs_data.sigma: ";
        //for(auto __v : gs_data.sigma)
            //Rcpp::Rcout<<__v<<", ";
        //Rcpp::Rcout<<std::endl;
    }
    else
        throw std::runtime_error("Error in FC_tau_mv::update, only possible priors are Normal-InvGamma and Normal. No other cases have been implemented. ");

}

