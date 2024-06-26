#ifndef GDFMM_GIBBSSAMPLER_MARGINAL_H
#define GDFMM_GIBBSSAMPLER_MARGINAL_H

// [[Rcpp::depends(RcppProgress)]]
#include <progress.hpp>      // For progress bar
#include <progress_bar.hpp>
#include <gsl/gsl_rng.h>     //For random number generators
#include <gsl/gsl_randist.h> //For random variates and probability density functions
#include <gsl/gsl_cdf.h> 	 //For cumulative density functions
#include <gsl/gsl_linalg.h>
#include "include_headers.h"
#include "recurrent_traits.h"

#include "FC_tau.h"
#include "FC_UMarginal.h"
#include "FC_LambdaMarginal.h"
#include "FC_gammaMarginal.h"
#include "FC_PartitionMarginal.h"

#include "GS_data.h"
#include "out_dataMarginal.h"
#include <chrono>

class GibbsSamplerMarginal {
public:
    unsigned int n_iter;
    unsigned int burn_in;
    unsigned int thin;
    void sample();

    // Constructor 
    GibbsSamplerMarginal( Eigen::MatrixXd const &data, unsigned int n_it, unsigned int b_in, unsigned int thn,
                          unsigned int seed, std::string P0_prior_name, bool FixPart, Rcpp::List option);
                
    // Data structure for the output
    out_dataMarginal out;
    
private:
    std::vector<std::shared_ptr<FullConditional> > FullConditionals; // vector of shared pointer to FC class
    sample::GSL_RNG random_engine; // GSL random engine to sample from random distribution
    GS_data gs_data; // data structure to store values that are updated during Gibbs Sampler
    //std::string model; // inutile?
    void store_params_values();
    //void store_tau();
    //void store_w_jk();
    void GS_Step();
    bool Partition_fixed;
};


#endif //GDFMM_GIBBSSAMPLER_H
