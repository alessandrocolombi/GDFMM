// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

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

static const R_CallMethodDef CallEntries[] = {
    {"_GDFMM_try_rcpp", (DL_FUNC) &_GDFMM_try_rcpp, 1},
    {"_GDFMM_EigenTest", (DL_FUNC) &_GDFMM_EigenTest, 0},
    {"_GDFMM_TestGSL", (DL_FUNC) &_GDFMM_TestGSL, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_GDFMM(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
