#ifndef __PARTITION_MV_H__
#define __PARTITION_MV_H__

#include "FullConditional.h"
#include "recurrent_traits.h"
#include <Rcpp.h>

class FullConditional;

class Partition_mv : public FullConditional{
protected:
    /* Fix Partition option */
    // Ho un problema. avendo aggiunto in FullConditional il membro keep_fixed, ora questa informazione è ripetuta. Però nel codice viene sempre usata Partition_fixed.
    // Per ora tengo entrambe, sarebbe sa sistemare togliendo Partition_fixed
    bool Partition_fixed;
public:
    std::vector< std::vector<unsigned int>> C; // matrix of c_ji (non ordered)
    std::set<unsigned int> s;  // A set which will be useful for ordering components
    std::vector<unsigned int> clust_out; // vector of ORDERED allocated components
    Partition_mv(){};
    Partition_mv(std::string na, const unsigned int d, const std::vector<unsigned int> & n_j, bool FixPart);
    ~Partition_mv(){};
    void update(GS_data& gs_data, const sample::GSL_RNG& gs_engine) override;
    double log_dmvnorm(const Individual& data_ji, const double& mu, const double& var) const;
    double log_dmvnorm2(Individual data_ji, const double& mu, const double& var) const;
    double log_dmvnorm2(Individual data_ji, const double& mu, const GDFMM_Traits::VecCol& cov_term, const double& var) const;
};

#endif
