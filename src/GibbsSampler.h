//
// Created by pietr on 12/12/2021.
//

#ifndef GDFMM_GIBBSSAMPLER_H
#define GDFMM_GIBBSSAMPLER_H

#include <gsl/gsl_rng.h>     //For random number generators
#include <gsl/gsl_randist.h> //For random variates and probability density functions
#include <gsl/gsl_cdf.h> 	 //For cumulative density functions
#include <gsl/gsl_bspline.h> //For spline operations
#include <gsl/gsl_linalg.h>
#include "include_headers.h"
#include "recurrent_traits.h"
#include "FullConditional.h"
#include "GS_data.h"

typedef std::vector<float> params;
using std::string;

class GibbsSampler {
public:
    static unsigned int n_iter;
    unsigned int burn_in;
    unsigned int thin;

    std::map<string, std::vector<float>> sample();
    GibbsSampler(*args);
    ~GibbsSampler();

private:
    sample::GSL_RNG random_engine;
    GS_data gs_data;
    std::map<string, params(n_iter)> output_data;  // Da decidere
    std::map<string, float> parameters;   // Forse sostituito da Gs_data
    string model;
    std::map<string, float> initial_values;  // Non più utile perchè questi dati saranno già presenti in GS-data alla costruzione
    std::vector<FullConditional*> FullConditionals;

    void store_params_values();
    void GS_Step();
    unsigned int seed;
};


#endif //GDFMM_GIBBSSAMPLER_H
