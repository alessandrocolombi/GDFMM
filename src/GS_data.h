#ifndef __GS_DATA_H
#define __GS_DATA_H

#include "include_headers.h"
#include "recurrent_traits.h"
#include "GSL_wrappers.h"
//#include "Partition.h"
//class Partition;
struct GS_data{
    /* DATA */

    // single values
    unsigned int d;
    unsigned int iterations;// number of groups
    unsigned int K; // number of allocated component ==> number of clusters
    unsigned int Mstar; // number of NON-allocated component
    unsigned int M; // total number of component
    double lambda; // M|lambda ~ Poi(lambda)
    double log_sum; // sum of log(U_j+1)*gamma_j : logarithm of 1/psi_prod
    // vectors
    std::vector<std::vector<double>> data; // our data, y_ji
    std::vector< std::vector<unsigned int>> Ctilde; //output partition
    std::vector<unsigned int> n_j; // number of elements in  each group (dimension: d)
    std::vector<unsigned int> N_k; // number of elements in each cluster
    std::vector<double> U; // auxiliary variable
    std::vector<double> gamma; // vector of d gamma, one for each group
    std::vector<double> mu; // vector of the mean for each component
    std::vector<double> sigma; // vector of the variance for each component
                               // N.B. sample::rnorm takes the s.d. as input ==> use sqrt(sigma[m])
    std::string prior="normal-inverse-gamma"; //Which prior are we using for tau? noga or normal inverse gamma?
    // matrix or vector of vectors
    GDFMM_Traits::MatRow S; // dxM matrix; allocated and NON-alloc together
    GDFMM_Traits::MatUnsCol N; // dxK matrix; only allocated components have n_jk>0
    // Partition
    // Partition *p; //Partition passed as reference because I've made a forward declaration (?)
    //-----------------------------------------------------------//
    /* CONSTRUCTOR */
    GS_data(Eigen::MatrixXd const &dat, unsigned int n_iter, unsigned int burnin, unsigned int thin,
                const sample::GSL_RNG& gs_engine, unsigned int Mstar0, unsigned int Lambda0,
                unsigned int mu0, unsigned int nu0, unsigned int sigma0);
    GS_data(){};
    ~GS_data(){};
    /* METHODS */
    void initialize_Partition(const std::vector<unsigned int>& n_j);
    void initialize_S(unsigned int M,  const sample::GSL_RNG& gs_engine);
    void allocate_S(unsigned int M);
    void initialize_tau(unsigned int M, double nu0, double mu0, double sigma0,
                        const sample::GSL_RNG& gs_engine);
    // update methods;
    void allocate_N(unsigned int K);
    void update_Ctilde(const std::vector< std::vector<unsigned int>> &C,
                            const std::vector<unsigned int> &clust_out);
    void update_log_sum();
    void allocate_tau(unsigned int M);
};

#endif
