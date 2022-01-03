#include "FC_S.h"

void FC_S::update(GS_data& gs_data, const sample::GSL_RNG& gs_engine){
    const unsigned int& d = gs_data.d;
    const unsigned int& K = gs_data.K;
    const unsigned int& Mstar = gs_data.Mstar;
    const std::vector<double>& U = gs_data.U;
    const std::vector<double>& gamma = gs_data.gamma;
    const GDFMM_Traits::MatUnsCol& N = gs_data.N;
    GDFMM_Traits::MatRow & S = gs_data.S; //non-const ref. because we modify it

    // Random sampler is created
    sample::rgamma Gamma;

    // Update routine
    for (unsigned j=0; j<d; j++) { //per ogni livello
        //S ALLOCATE
        for (unsigned k=0; k<K; k++) {//per ogni comp allocata
            S(j, k) = Gamma(gs_engine, N(j, k) + gamma[j], U[j] + 1);
        }

        //S NON ALLOCATE
        if (Mstar > 0) { // se c'è almeno una componente non allocata
            for (unsigned mstar=0; mstar<Mstar; mstar++) {
                S(j, mstar) = Gamma(gs_engine, gamma[j], U[j] + 1);
            }
        }
    }

}





