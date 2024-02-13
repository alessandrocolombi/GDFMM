// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <RcppEigen.h>
#include <RcppGSL.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// GDFMM_sampler_c
Rcpp::List GDFMM_sampler_c(Eigen::MatrixXd const& dat, unsigned int n_iter, unsigned int burn_in, unsigned int thin, unsigned int seed, Rcpp::String P0_prior_name, bool FixPart, Rcpp::List option);
RcppExport SEXP _GDFMM_GDFMM_sampler_c(SEXP datSEXP, SEXP n_iterSEXP, SEXP burn_inSEXP, SEXP thinSEXP, SEXP seedSEXP, SEXP P0_prior_nameSEXP, SEXP FixPartSEXP, SEXP optionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd const& >::type dat(datSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n_iter(n_iterSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type burn_in(burn_inSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type thin(thinSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type seed(seedSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type P0_prior_name(P0_prior_nameSEXP);
    Rcpp::traits::input_parameter< bool >::type FixPart(FixPartSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type option(optionSEXP);
    rcpp_result_gen = Rcpp::wrap(GDFMM_sampler_c(dat, n_iter, burn_in, thin, seed, P0_prior_name, FixPart, option));
    return rcpp_result_gen;
END_RCPP
}
// GDFMM_marginal_sampler_c
Rcpp::List GDFMM_marginal_sampler_c(Eigen::MatrixXd const& dat, unsigned int n_iter, unsigned int burn_in, unsigned int thin, unsigned int seed, Rcpp::String P0_prior_name, bool FixPart, Rcpp::List option);
RcppExport SEXP _GDFMM_GDFMM_marginal_sampler_c(SEXP datSEXP, SEXP n_iterSEXP, SEXP burn_inSEXP, SEXP thinSEXP, SEXP seedSEXP, SEXP P0_prior_nameSEXP, SEXP FixPartSEXP, SEXP optionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd const& >::type dat(datSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n_iter(n_iterSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type burn_in(burn_inSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type thin(thinSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type seed(seedSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type P0_prior_name(P0_prior_nameSEXP);
    Rcpp::traits::input_parameter< bool >::type FixPart(FixPartSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type option(optionSEXP);
    rcpp_result_gen = Rcpp::wrap(GDFMM_marginal_sampler_c(dat, n_iter, burn_in, thin, seed, P0_prior_name, FixPart, option));
    return rcpp_result_gen;
END_RCPP
}
// MCMC_conditional_c
Rcpp::List MCMC_conditional_c(const Rcpp::List& data_list, unsigned int n_iter, unsigned int burn_in, unsigned int thin, unsigned int seed, Rcpp::String P0_prior_name, bool FixPart, Rcpp::String algorithm, Rcpp::List option);
RcppExport SEXP _GDFMM_MCMC_conditional_c(SEXP data_listSEXP, SEXP n_iterSEXP, SEXP burn_inSEXP, SEXP thinSEXP, SEXP seedSEXP, SEXP P0_prior_nameSEXP, SEXP FixPartSEXP, SEXP algorithmSEXP, SEXP optionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::List& >::type data_list(data_listSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n_iter(n_iterSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type burn_in(burn_inSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type thin(thinSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type seed(seedSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type P0_prior_name(P0_prior_nameSEXP);
    Rcpp::traits::input_parameter< bool >::type FixPart(FixPartSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type algorithm(algorithmSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type option(optionSEXP);
    rcpp_result_gen = Rcpp::wrap(MCMC_conditional_c(data_list, n_iter, burn_in, thin, seed, P0_prior_name, FixPart, algorithm, option));
    return rcpp_result_gen;
END_RCPP
}
// compute_logC
Rcpp::NumericVector compute_logC(const unsigned int& n, const double& scale, const double& location);
RcppExport SEXP _GDFMM_compute_logC(SEXP nSEXP, SEXP scaleSEXP, SEXP locationSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type scale(scaleSEXP);
    Rcpp::traits::input_parameter< const double& >::type location(locationSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_logC(n, scale, location));
    return rcpp_result_gen;
END_RCPP
}
// p_distinct_prior_c
double p_distinct_prior_c(const unsigned int& k, const Rcpp::NumericVector& n_j, const Rcpp::NumericVector& gamma_j, const Rcpp::String& prior, const Rcpp::List& prior_param, unsigned int M_max);
RcppExport SEXP _GDFMM_p_distinct_prior_c(SEXP kSEXP, SEXP n_jSEXP, SEXP gamma_jSEXP, SEXP priorSEXP, SEXP prior_paramSEXP, SEXP M_maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type k(kSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type n_j(n_jSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type gamma_j(gamma_jSEXP);
    Rcpp::traits::input_parameter< const Rcpp::String& >::type prior(priorSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type prior_param(prior_paramSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type M_max(M_maxSEXP);
    rcpp_result_gen = Rcpp::wrap(p_distinct_prior_c(k, n_j, gamma_j, prior, prior_param, M_max));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_GDFMM_GDFMM_sampler_c", (DL_FUNC) &_GDFMM_GDFMM_sampler_c, 8},
    {"_GDFMM_GDFMM_marginal_sampler_c", (DL_FUNC) &_GDFMM_GDFMM_marginal_sampler_c, 8},
    {"_GDFMM_MCMC_conditional_c", (DL_FUNC) &_GDFMM_MCMC_conditional_c, 9},
    {"_GDFMM_compute_logC", (DL_FUNC) &_GDFMM_compute_logC, 3},
    {"_GDFMM_p_distinct_prior_c", (DL_FUNC) &_GDFMM_p_distinct_prior_c, 6},
    {NULL, NULL, 0}
};

RcppExport void R_init_GDFMM(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
