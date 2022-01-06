#include "Partition.h"

void Partition::update(GS_data& gs_data, const sample::GSL_RNG& gs_engine){
  // From gs_data all needed variable are retrived

  unsigned int k = gs_data.K; // number of cluster
  unsigned int d = gs_data.d; // number of group
  unsigned int M = gs_data.M; // number of components
  const GDFMM_Traits::MatRow& S = gs_data.S; // Matrix of weights
  std::vector<unsigned int> n_j = gs_data.n_j;// number of observation per group
  const std::vector<double>& mu = gs_data.mu; // Vector of means
  const std::vector<double>& sigma = gs_data.sigma; // Vector of standard deviations
  std::vector<std::vector<double>> probs; // matrix of probability
  std::set<unsigned int> s; // A set which will be useful for cluster
  // Define data taken from gs_data
  const std::vector<std::vector<double>>& data = gs_data.data;
  // Initialization of probs_max
  double probs_max;

  sample::discrete Discrete;

  // Generate matrix of "probabilities" for each observation
  for(unsigned j=0; j<d; j++){
    std::vector<double> v(n_j[j]);
    for(unsigned i=0; i<n_j[j]; i++){
      for(unsigned m=0; m<M; m++){
        v.push_back(log(S(j,m)+log(Partition::normpdf(data[j][i],mu[m],sigma[m])))); //potrebbe essere sbagliato anche questo e infatti è sbagliato
        //in every and for every component put the log likelihood
      }
      probs.push_back(v); //Create a vector for every J
      probs_max=*max_element(probs[i].begin(), probs[i].end());
      for(unsigned m=0; m<M; m++){
        probs[i][m] = exp(probs[i][m] - probs_max);
        }

    }

    // Assegno tramite il sample su probs a ogni cluster un'etichetta
    //If M==1 populate C matrix with ones
    if (M == 1){
        std::vector<double> v(n_j[j],1.0);
        C.push_back(v);

    }
    else{
      for (unsigned i=0; i<n_j[j]; i++) {
          double* arrayprobs = &probs[i][0];
          // ANDRE: QUA NON HO CAPITO COSA STA SUCCEDENDO.
          //BOSCA->ANDRE: È UNA PARTE UN PO' SBATTI, PRATICAMENTE LA DISCRETE CHE HO DEFINITO IN GSL_WRAPPERS PERCHÈ NON ERA DEFINITA, PRENDE IN ENTR
      //IN ENTRATA UN ARRAY CHE È ARRAYPROBS, HO TROVATO QUESTO MODO PER AVERE VECTOR->ARRAY MA MI SA CHE NON FUNZIONA
        std::vector<double> dis(Discrete(gs_engine, arrayprobs), Discrete(gs_engine, arrayprobs)+M);
        C.push_back(dis);
    }/* per ogni dato nel livello j
    Creiamo una matrice della stessa dimensione della matrice dei dati,
    dove ogni riga contiene le etichette non ordinate per ciascun dato di
    quel livello */
  };

  //create vector of allocated components
  for(unsigned j=0; j<d; j++){
    for(unsigned i=0; i<n_j[j]; i++){
      s.insert(C[j][i]);
      clust_out.assign(s.begin(),s.end());
    }
  }
  k = clust_out.size();
  gs_data.K = k; // updating K in the struct gs_data
  gs_data.initialize_N(k); // initialize N according to new K
}

}


double Partition::normpdf(double x, double u, double s) const {
  const double ONE_OVER_SQRT_2PI = 0.39894228040143267793994605993438;
  return (ONE_OVER_SQRT_2PI/s)*exp(-0.5*(x-u)*(x-u)/s);
}
