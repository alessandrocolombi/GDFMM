#include "FC_Lambda.h"

void FC_Lambda::update(GS_data& gs_data, const sample::GSL_RNG& gs_engine){
    // From gs_data all needed variable are retrived
    const unsigned int& k = gs_data.K;
    const unsigned int& d = gs_data.d;
    const double& log_sum = gs_data.log_sum;

    //Rcpp::Rcout<<"log_sum:"<<std::endl<<log_sum<<std::endl;

    // Random sampler is created
    sample::rgamma Gamma;

    // UPDATE ROUTINE
    double a2_star = static_cast<double>( d*(k-1) ) + a2;

    // Computation of the weight for the "first" gamma distr.
    double p0 = (a2_star)/((a2_star-k)+k*(b2+1)*exp(log_sum));
    // Select, via extraction from a uniform, which distribution sample from
    bool select_p0 = binary_decision(p0, gs_engine);

    if(select_p0)
        gs_data.lambda = Gamma(gs_engine, a2_star + 1, 1 /(b2 + 1 - exp(-log_sum)) );
    else
        gs_data.lambda = Gamma(gs_engine, a2_star, 1 /(b2 + 1 - exp(-log_sum)) );
}
