#ifndef __GDFMMEXPORT_HPP__
#define __GDFMMEXPORT_HPP__

// [[Rcpp::depends(RcppEigen)]]
// [[Rcpp::depends(RcppParallel)]]
#define STRICT_R_HEADERS
#include <Rcpp.h>
#include <RcppEigen.h>
#include "include_headers.h"
#include "recurrent_traits.h"
#include "GSL_wrappers.h"
#include "GibbsSampler.h"


//' Title Rcpp function
//'
//' @export
// [[Rcpp::export]]
int try_rcpp(int x){
	Rcpp::Rcout<<"Inside test function"<<std::endl;
	return x+10;
}

//' GDFMM sampler with M unknown
// [[Rcpp::export]]
Rcpp::List GDFMM_sampler_c( Eigen::MatrixXd const & dat, unsigned int n_iter, unsigned int burn_in,
			 unsigned int thin , unsigned int seed, Rcpp::String P0_prior_name, Rcpp::List option){

	// Note that there is not the //' @export command. The user can not call this function.
	// I am afraid that Rcpp can take only Column major matrices. (not sure)
	// Do not use deafult values here
	Rcpp::Rcout<<"This is the Rcpp function"<<std::endl;
	Rcpp::Rcout<<"In c++ environment you can create custom c++ classes"<<std::endl;
	  //GS_data g(dat, n_iter,burn_in,thin); non posso più inizializzare gsdata fuori
    GibbsSampler Gibbs(dat, n_iter, burn_in, thin, seed, P0_prior_name, option);
    Gibbs.sample();
	out_data out = Gibbs.out;
    std::vector<int> Mstar = out.Mstar;
    std::vector<int> K = out.K;
    std::vector<double> lambda = out.lambda;
    std::vector<std::vector<double>> U = out.U;
    std::vector<std::vector<double>> gamma = out.gamma;

    // Parameters param(niter, burnin, thin);   // example of another class that stores useful options
	if (P0_prior_name == "Normal-InvGamma")
	{
		// Hyperparameters hy(param1,param2,param3); 			//example of the creation of a custom c++ class
		//P0Prior P0(hy.nu, ...);
			    //--> example of the creation of a custom c++ class that defines the P0prior to be used in this case

		//SamplingStrategy sampler_obj(data, param, hy, P0);   //example of sampler object creation
		//sampler_obj(...);
				//--> run the sampler. prefer to use the call operator instead of a method called run().


		//Post-processing and return

		//you can mix types in Rcpp lists
		return Rcpp::List::create ( Rcpp::Named("Mstar")= Mstar,
                                  	Rcpp::Named("K")= K,
                                  	Rcpp::Named("lambda")=lambda
                                  	//Rcpp::Named("U")= U
                                  	//Rcpp::Named("gamma")=gamma
                                  	);

	}
	else if (P0_prior_name == "Normal-Gamma")
	{
		//Similar as before
		return Rcpp::List::create ( Rcpp::Named("return_1")= dat,
		                            Rcpp::Named("return_2")= 10,
		                            Rcpp::Named("return_3")= "string" );
	}
	else
		throw std::runtime_error("Runtime error. This avoid R session to abort in favour of a meaningful error.");
}

//' GDFMM sampler with M fixed
// [[Rcpp::export]]
Rcpp::List GDFMM_sampler_M_c( Eigen::MatrixXd const & dat, unsigned int M, unsigned int n_iter, unsigned int burn_in,
			 unsigned int thin , unsigned int seed, Rcpp::String P0_prior_name, Rcpp::List option){

	// Note that there is not the //' @export command. The user can not call this function.
	// I am afraid that Rcpp can take only Column major matrices. (not sure)
	// Do not use deafult values here
	Rcpp::Rcout<<"This is the Rcpp function"<<std::endl;
	Rcpp::Rcout<<"In c++ environment you can create custom c++ classes"<<std::endl;
	  //GS_data g(dat, n_iter,burn_in,thin); non posso più inizializzare gsdata fuori
    GibbsSampler Gibbs(dat, n_iter, burn_in, thin, seed, P0_prior_name, M, option);
    Gibbs.sample();
	out_data out = Gibbs.out;
	std::vector<std::vector<double>> mu = out.tau[0];
	std::vector<std::vector<double>> sigma = out.tau[1];
    // std::vector<std::vector<double>> S = out.S;

    // Parameters param(niter, burnin, thin);   // example of another class that stores useful options
	if (P0_prior_name == "Normal-InvGamma")
	{
		// Hyperparameters hy(param1,param2,param3); 			//example of the creation of a custom c++ class
		//P0Prior P0(hy.nu, ...);
			    //--> example of the creation of a custom c++ class that defines the P0prior to be used in this case

		//SamplingStrategy sampler_obj(data, param, hy, P0);   //example of sampler object creation
		//sampler_obj(...);
				//--> run the sampler. prefer to use the call operator instead of a method called run().


		//Post-processing and return

		//you can mix types in Rcpp lists
		return Rcpp::List::create ( Rcpp::Named("mu")= mu,
                                  	Rcpp::Named("sigma")= sigma
                                  	);

	}
	else if (P0_prior_name == "Normal-Gamma")
	{
		//Similar as before
		return Rcpp::List::create ( Rcpp::Named("return_1")= dat,
		                            Rcpp::Named("return_2")= 10,
		                            Rcpp::Named("return_3")= "string" );
	}
	else
		throw std::runtime_error("Runtime error. This avoid R session to abort in favour of a meaningful error.");
}


#endif
