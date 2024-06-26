#ifndef GDFMM_FC_S_H
#define GDFMM_FC_S_H

#include "FullConditional.h"
#include "recurrent_traits.h"


class FC_S : public FullConditional{

public:

    FC_S(bool _keepfixed):FullConditional("S",_keepfixed){};
    FC_S(std::string na, bool _keepfixed):FullConditional(na,_keepfixed){};
    ~FC_S() {};
    void update(GS_data& gs_data, const sample::GSL_RNG& gs_engine) override;

};

#endif //GDFMM_FC_S_H
