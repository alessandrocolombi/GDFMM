#ifndef __OUTDATA_H
#define __OUTDATA_H

#include "include_headers.h"
#include "recurrent_traits.h"
struct out_data{
  /* DATA */
  // single values
  std::vector<int> K; // number of allocated component ==> number of clusters
  std::vector<int> Mstar; // number of NON-allocated component
  std::vector<double> lambda; // M|lambda ~ Poi(lambda)
  //vectors
  std::vector<std::vector< std::vector<unsigned int>>> Ctilde;
  std::vector<GDFMM_Traits::MatRow> S;
  std::vector<std::vector< std::vector<double>>> tau;
  //output
  std::vector<std::vector<double>> U; // auxiliary variable
  std::vector<std::vector<double>> gamma; // vector of d gamma, one for each group
  //-----------------------------------------------------------//
  /* CONSTRUCTOR */
};

#endif