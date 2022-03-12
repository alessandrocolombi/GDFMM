// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <RcppEigen.h>
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
// falling_factorial
double falling_factorial(double x, int n);
RcppExport SEXP _GDFMM_falling_factorial(SEXP xSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(falling_factorial(x, n));
    return rcpp_result_gen;
END_RCPP
}
// calcola_stirling
Rcpp::NumericVector calcola_stirling(int n, double gamma, double r);
RcppExport SEXP _GDFMM_calcola_stirling(SEXP nSEXP, SEXP gammaSEXP, SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_stirling(n, gamma, r));
    return rcpp_result_gen;
END_RCPP
}
// calcola_stirling_ricor
Rcpp::NumericVector calcola_stirling_ricor(int n, double gamma, double r);
RcppExport SEXP _GDFMM_calcola_stirling_ricor(SEXP nSEXP, SEXP gammaSEXP, SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_stirling_ricor(n, gamma, r));
    return rcpp_result_gen;
END_RCPP
}
// calcola_stirling_ricor_centr
Rcpp::NumericVector calcola_stirling_ricor_centr(double gamma, int n);
RcppExport SEXP _GDFMM_calcola_stirling_ricor_centr(SEXP gammaSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_stirling_ricor_centr(gamma, n));
    return rcpp_result_gen;
END_RCPP
}
// calcola_stirling_ricor_log
Rcpp::NumericVector calcola_stirling_ricor_log(int n, double gamma, double r);
RcppExport SEXP _GDFMM_calcola_stirling_ricor_log(SEXP nSEXP, SEXP gammaSEXP, SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_stirling_ricor_log(n, gamma, r));
    return rcpp_result_gen;
END_RCPP
}
// calcola_stirling_ricor_log_centrali
Rcpp::NumericVector calcola_stirling_ricor_log_centrali(int n, double gamma);
RcppExport SEXP _GDFMM_calcola_stirling_ricor_log_centrali(SEXP nSEXP, SEXP gammaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_stirling_ricor_log_centrali(n, gamma));
    return rcpp_result_gen;
END_RCPP
}
// lgfactorial
arma::vec lgfactorial(int n, double sigma);
RcppExport SEXP _GDFMM_lgfactorial(SEXP nSEXP, SEXP sigmaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    rcpp_result_gen = Rcpp::wrap(lgfactorial(n, sigma));
    return rcpp_result_gen;
END_RCPP
}
// lgfactorials
arma::mat lgfactorials(int n, double sigma);
RcppExport SEXP _GDFMM_lgfactorials(SEXP nSEXP, SEXP sigmaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    rcpp_result_gen = Rcpp::wrap(lgfactorials(n, sigma));
    return rcpp_result_gen;
END_RCPP
}
// lgfactorial_ns
arma::vec lgfactorial_ns(int n, double sigma);
RcppExport SEXP _GDFMM_lgfactorial_ns(SEXP nSEXP, SEXP sigmaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    rcpp_result_gen = Rcpp::wrap(lgfactorial_ns(n, sigma));
    return rcpp_result_gen;
END_RCPP
}
// lastirling1
arma::vec lastirling1(int n);
RcppExport SEXP _GDFMM_lastirling1(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(lastirling1(n));
    return rcpp_result_gen;
END_RCPP
}
// lastirlings1
arma::mat lastirlings1(int n);
RcppExport SEXP _GDFMM_lastirlings1(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(lastirlings1(n));
    return rcpp_result_gen;
END_RCPP
}
// EigenTest
void EigenTest();
RcppExport SEXP _GDFMM_EigenTest() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    EigenTest();
    return R_NilValue;
END_RCPP
}
// TestGSL
void TestGSL();
RcppExport SEXP _GDFMM_TestGSL() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    TestGSL();
    return R_NilValue;
END_RCPP
}
// calcola_stirling_old
Rcpp::NumericVector calcola_stirling_old(double gamma, int n);
RcppExport SEXP _GDFMM_calcola_stirling_old(SEXP gammaSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_stirling_old(gamma, n));
    return rcpp_result_gen;
END_RCPP
}
// calcola_stirling_ricor_old
Rcpp::NumericVector calcola_stirling_ricor_old(double gamma, unsigned int n);
RcppExport SEXP _GDFMM_calcola_stirling_ricor_old(SEXP gammaSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_stirling_ricor_old(gamma, n));
    return rcpp_result_gen;
END_RCPP
}
// calcola_stirling_ricor_abs_old
Rcpp::NumericVector calcola_stirling_ricor_abs_old(double gamma, unsigned int n);
RcppExport SEXP _GDFMM_calcola_stirling_ricor_abs_old(SEXP gammaSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_stirling_ricor_abs_old(gamma, n));
    return rcpp_result_gen;
END_RCPP
}
// calcola_stirling_ricor_log_old
Rcpp::NumericVector calcola_stirling_ricor_log_old(double gamma, unsigned int n);
RcppExport SEXP _GDFMM_calcola_stirling_ricor_log_old(SEXP gammaSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_stirling_ricor_log_old(gamma, n));
    return rcpp_result_gen;
END_RCPP
}
// calcola_generalized_factorial_ricor_log_old
Rcpp::NumericVector calcola_generalized_factorial_ricor_log_old(double gamma, unsigned int n);
RcppExport SEXP _GDFMM_calcola_generalized_factorial_ricor_log_old(SEXP gammaSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_generalized_factorial_ricor_log_old(gamma, n));
    return rcpp_result_gen;
END_RCPP
}
// calcola_generalized_factorial_ricor_log_matrice_old
Rcpp::NumericMatrix calcola_generalized_factorial_ricor_log_matrice_old(double gamma, unsigned int n);
RcppExport SEXP _GDFMM_calcola_generalized_factorial_ricor_log_matrice_old(SEXP gammaSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(calcola_generalized_factorial_ricor_log_matrice_old(gamma, n));
    return rcpp_result_gen;
END_RCPP
}
// try_rcpp
int try_rcpp(int x);
RcppExport SEXP _GDFMM_try_rcpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(try_rcpp(x));
    return rcpp_result_gen;
END_RCPP
}
// raising_factorial
double raising_factorial(const unsigned int& n, const double& a);
RcppExport SEXP _GDFMM_raising_factorial(SEXP nSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(raising_factorial(n, a));
    return rcpp_result_gen;
END_RCPP
}
// log_raising_factorial
double log_raising_factorial(const unsigned int& n, const double& a);
RcppExport SEXP _GDFMM_log_raising_factorial(SEXP nSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(log_raising_factorial(n, a));
    return rcpp_result_gen;
END_RCPP
}
// raising_factorial_poch
double raising_factorial_poch(const unsigned int& n, const double& a);
RcppExport SEXP _GDFMM_raising_factorial_poch(SEXP nSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(raising_factorial_poch(n, a));
    return rcpp_result_gen;
END_RCPP
}
// log_raising_factorial_poch
double log_raising_factorial_poch(const unsigned int& n, const double& a);
RcppExport SEXP _GDFMM_log_raising_factorial_poch(SEXP nSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(log_raising_factorial_poch(n, a));
    return rcpp_result_gen;
END_RCPP
}
// my_falling_factorial
double my_falling_factorial(const unsigned int& n, const double& a);
RcppExport SEXP _GDFMM_my_falling_factorial(SEXP nSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(my_falling_factorial(n, a));
    return rcpp_result_gen;
END_RCPP
}
// my_log_falling_factorial
double my_log_falling_factorial(const unsigned int& n, const double& a);
RcppExport SEXP _GDFMM_my_log_falling_factorial(SEXP nSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(my_log_falling_factorial(n, a));
    return rcpp_result_gen;
END_RCPP
}
// my_falling_factorial_old
double my_falling_factorial_old(const unsigned int& n, const double& a);
RcppExport SEXP _GDFMM_my_falling_factorial_old(SEXP nSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(my_falling_factorial_old(n, a));
    return rcpp_result_gen;
END_RCPP
}
// my_log_falling_factorial_old
double my_log_falling_factorial_old(const unsigned int& n, const double& a);
RcppExport SEXP _GDFMM_my_log_falling_factorial_old(SEXP nSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(my_log_falling_factorial_old(n, a));
    return rcpp_result_gen;
END_RCPP
}
// compute_Pochhammer
double compute_Pochhammer(const unsigned int& x, const double& a);
RcppExport SEXP _GDFMM_compute_Pochhammer(SEXP xSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_Pochhammer(x, a));
    return rcpp_result_gen;
END_RCPP
}
// compute_log_Pochhammer
double compute_log_Pochhammer(const unsigned int& x, const double& a);
RcppExport SEXP _GDFMM_compute_log_Pochhammer(SEXP xSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const double& >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_log_Pochhammer(x, a));
    return rcpp_result_gen;
END_RCPP
}
// build_logC_matrix
void build_logC_matrix(const unsigned int& n, const unsigned int& k, const double& s, const double& r, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>& res);
RcppExport SEXP _GDFMM_build_logC_matrix(SEXP nSEXP, SEXP kSEXP, SEXP sSEXP, SEXP rSEXP, SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const unsigned int& >::type k(kSEXP);
    Rcpp::traits::input_parameter< const double& >::type s(sSEXP);
    Rcpp::traits::input_parameter< const double& >::type r(rSEXP);
    Rcpp::traits::input_parameter< Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>& >::type res(resSEXP);
    build_logC_matrix(n, k, s, r, res);
    return R_NilValue;
END_RCPP
}
// my_logC
Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor> my_logC(const unsigned int& n, const double& scale, const double& location);
RcppExport SEXP _GDFMM_my_logC(SEXP nSEXP, SEXP scaleSEXP, SEXP locationSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type scale(scaleSEXP);
    Rcpp::traits::input_parameter< const double& >::type location(locationSEXP);
    rcpp_result_gen = Rcpp::wrap(my_logC(n, scale, location));
    return rcpp_result_gen;
END_RCPP
}
// my_logC2
Eigen::VectorXd my_logC2(const unsigned int& n, const double& scale, const double& location);
RcppExport SEXP _GDFMM_my_logC2(SEXP nSEXP, SEXP scaleSEXP, SEXP locationSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type scale(scaleSEXP);
    Rcpp::traits::input_parameter< const double& >::type location(locationSEXP);
    rcpp_result_gen = Rcpp::wrap(my_logC2(n, scale, location));
    return rcpp_result_gen;
END_RCPP
}
// my_logC2_central
Eigen::VectorXd my_logC2_central(const unsigned int& n, const double& scale);
RcppExport SEXP _GDFMM_my_logC2_central(SEXP nSEXP, SEXP scaleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double& >::type scale(scaleSEXP);
    rcpp_result_gen = Rcpp::wrap(my_logC2_central(n, scale));
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
double p_distinct_prior_c(const unsigned int& k, const Rcpp::NumericVector& n_groups, const Rcpp::NumericVector& gamma_groups, const Rcpp::String& prior, const Rcpp::List& prior_param, unsigned int M_max);
RcppExport SEXP _GDFMM_p_distinct_prior_c(SEXP kSEXP, SEXP n_groupsSEXP, SEXP gamma_groupsSEXP, SEXP priorSEXP, SEXP prior_paramSEXP, SEXP M_maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type k(kSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type n_groups(n_groupsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type gamma_groups(gamma_groupsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::String& >::type prior(priorSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type prior_param(prior_paramSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type M_max(M_maxSEXP);
    rcpp_result_gen = Rcpp::wrap(p_distinct_prior_c(k, n_groups, gamma_groups, prior, prior_param, M_max));
    return rcpp_result_gen;
END_RCPP
}
// Test_multiple_groups_c
double Test_multiple_groups_c(const unsigned int& k, const Rcpp::NumericVector& n_groups, const Rcpp::NumericVector& gamma_groups, const Rcpp::String& prior, const Rcpp::List& prior_param, unsigned int M_max);
RcppExport SEXP _GDFMM_Test_multiple_groups_c(SEXP kSEXP, SEXP n_groupsSEXP, SEXP gamma_groupsSEXP, SEXP priorSEXP, SEXP prior_paramSEXP, SEXP M_maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const unsigned int& >::type k(kSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type n_groups(n_groupsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type gamma_groups(gamma_groupsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::String& >::type prior(priorSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type prior_param(prior_paramSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type M_max(M_maxSEXP);
    rcpp_result_gen = Rcpp::wrap(Test_multiple_groups_c(k, n_groups, gamma_groups, prior, prior_param, M_max));
    return rcpp_result_gen;
END_RCPP
}
// Test_Prior
void Test_Prior();
RcppExport SEXP _GDFMM_Test_Prior() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Test_Prior();
    return R_NilValue;
END_RCPP
}
// Test_prod_sum
void Test_prod_sum();
RcppExport SEXP _GDFMM_Test_prod_sum() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Test_prod_sum();
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_GDFMM_GDFMM_sampler_c", (DL_FUNC) &_GDFMM_GDFMM_sampler_c, 8},
    {"_GDFMM_falling_factorial", (DL_FUNC) &_GDFMM_falling_factorial, 2},
    {"_GDFMM_calcola_stirling", (DL_FUNC) &_GDFMM_calcola_stirling, 3},
    {"_GDFMM_calcola_stirling_ricor", (DL_FUNC) &_GDFMM_calcola_stirling_ricor, 3},
    {"_GDFMM_calcola_stirling_ricor_centr", (DL_FUNC) &_GDFMM_calcola_stirling_ricor_centr, 2},
    {"_GDFMM_calcola_stirling_ricor_log", (DL_FUNC) &_GDFMM_calcola_stirling_ricor_log, 3},
    {"_GDFMM_calcola_stirling_ricor_log_centrali", (DL_FUNC) &_GDFMM_calcola_stirling_ricor_log_centrali, 2},
    {"_GDFMM_lgfactorial", (DL_FUNC) &_GDFMM_lgfactorial, 2},
    {"_GDFMM_lgfactorials", (DL_FUNC) &_GDFMM_lgfactorials, 2},
    {"_GDFMM_lgfactorial_ns", (DL_FUNC) &_GDFMM_lgfactorial_ns, 2},
    {"_GDFMM_lastirling1", (DL_FUNC) &_GDFMM_lastirling1, 1},
    {"_GDFMM_lastirlings1", (DL_FUNC) &_GDFMM_lastirlings1, 1},
    {"_GDFMM_EigenTest", (DL_FUNC) &_GDFMM_EigenTest, 0},
    {"_GDFMM_TestGSL", (DL_FUNC) &_GDFMM_TestGSL, 0},
    {"_GDFMM_calcola_stirling_old", (DL_FUNC) &_GDFMM_calcola_stirling_old, 2},
    {"_GDFMM_calcola_stirling_ricor_old", (DL_FUNC) &_GDFMM_calcola_stirling_ricor_old, 2},
    {"_GDFMM_calcola_stirling_ricor_abs_old", (DL_FUNC) &_GDFMM_calcola_stirling_ricor_abs_old, 2},
    {"_GDFMM_calcola_stirling_ricor_log_old", (DL_FUNC) &_GDFMM_calcola_stirling_ricor_log_old, 2},
    {"_GDFMM_calcola_generalized_factorial_ricor_log_old", (DL_FUNC) &_GDFMM_calcola_generalized_factorial_ricor_log_old, 2},
    {"_GDFMM_calcola_generalized_factorial_ricor_log_matrice_old", (DL_FUNC) &_GDFMM_calcola_generalized_factorial_ricor_log_matrice_old, 2},
    {"_GDFMM_try_rcpp", (DL_FUNC) &_GDFMM_try_rcpp, 1},
    {"_GDFMM_raising_factorial", (DL_FUNC) &_GDFMM_raising_factorial, 2},
    {"_GDFMM_log_raising_factorial", (DL_FUNC) &_GDFMM_log_raising_factorial, 2},
    {"_GDFMM_raising_factorial_poch", (DL_FUNC) &_GDFMM_raising_factorial_poch, 2},
    {"_GDFMM_log_raising_factorial_poch", (DL_FUNC) &_GDFMM_log_raising_factorial_poch, 2},
    {"_GDFMM_my_falling_factorial", (DL_FUNC) &_GDFMM_my_falling_factorial, 2},
    {"_GDFMM_my_log_falling_factorial", (DL_FUNC) &_GDFMM_my_log_falling_factorial, 2},
    {"_GDFMM_my_falling_factorial_old", (DL_FUNC) &_GDFMM_my_falling_factorial_old, 2},
    {"_GDFMM_my_log_falling_factorial_old", (DL_FUNC) &_GDFMM_my_log_falling_factorial_old, 2},
    {"_GDFMM_compute_Pochhammer", (DL_FUNC) &_GDFMM_compute_Pochhammer, 2},
    {"_GDFMM_compute_log_Pochhammer", (DL_FUNC) &_GDFMM_compute_log_Pochhammer, 2},
    {"_GDFMM_build_logC_matrix", (DL_FUNC) &_GDFMM_build_logC_matrix, 5},
    {"_GDFMM_my_logC", (DL_FUNC) &_GDFMM_my_logC, 3},
    {"_GDFMM_my_logC2", (DL_FUNC) &_GDFMM_my_logC2, 3},
    {"_GDFMM_my_logC2_central", (DL_FUNC) &_GDFMM_my_logC2_central, 2},
    {"_GDFMM_compute_logC", (DL_FUNC) &_GDFMM_compute_logC, 3},
    {"_GDFMM_p_distinct_prior_c", (DL_FUNC) &_GDFMM_p_distinct_prior_c, 6},
    {"_GDFMM_Test_multiple_groups_c", (DL_FUNC) &_GDFMM_Test_multiple_groups_c, 6},
    {"_GDFMM_Test_Prior", (DL_FUNC) &_GDFMM_Test_Prior, 0},
    {"_GDFMM_Test_prod_sum", (DL_FUNC) &_GDFMM_Test_prod_sum, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_GDFMM(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
