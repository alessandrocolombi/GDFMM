#ifndef __TESTGSL_HPP__
#define __TESTGSL_HPP__


// [[Rcpp::depends(RcppEigen)]]
// [[Rcpp::depends(RcppParallel)]]
#define STRICT_R_HEADERS
#include <Rcpp.h>
#include <RcppEigen.h>
#include "include_headers.h"
#include "recurrent_traits.h"
#include "GSL_wrappers.h"

using namespace GDFMM_Traits;

//' Testing GSL wrappers
//'
//' @export
// [[Rcpp::export]]
void TestGSL(){

	int Nrep = 10;

	Rcpp::Rcout<<"###########################"<<std::endl;
	Rcpp::Rcout<<"  Random number Genarator  "<<std::endl;
	Rcpp::Rcout<<"###########################"<<std::endl;

	sample::GSL_RNG engine1(12345); //engine with seed
	sample::GSL_RNG engine2(0); 	//same constructor but random seed
	sample::GSL_RNG engine3;		//default constructor, random seed

	Rcpp::Rcout<<"##########################"<<std::endl;
	Rcpp::Rcout<<"   Uniform distribution  "<<std::endl;
	Rcpp::Rcout<<"##########################"<<std::endl;

	sample::runif 	  Unif;			  //create the object
	sample::runif_int Unif_int;		  //create the object

	Rcpp::Rcout<<"Sequence using selected seed. Run the function twice, you get the same values"<<std::endl;
	for(int i = 0; i < Nrep; ++i){
		Rcpp::Rcout<<" "<<Unif(engine1)<<" ||";
	}
	Rcpp::Rcout<<std::endl<<std::endl;
	Rcpp::Rcout<<"Same but with integers in 0-9"<<std::endl;
	for(int i = 0; i < Nrep; ++i){
		Rcpp::Rcout<<" "<<Unif_int(engine1, 10)<<" ||";
	}
	Rcpp::Rcout<<std::endl<<std::endl;
	Rcpp::Rcout<<"Using engine with random seed (engine2 or engine3). Run twice, get different sequence"<<std::endl;
	for(int i = 0; i < Nrep; ++i){
		Rcpp::Rcout<<" "<<Unif(engine2)<<" ||";
	}
	Rcpp::Rcout<<std::endl<<std::endl;
	Rcpp::Rcout<<"Which is equivalent to Unif()"<<std::endl;
	for(int i = 0; i < Nrep; ++i){
		Rcpp::Rcout<<" "<<Unif()<<" ||";
	}
	Rcpp::Rcout<<std::endl<<std::endl;
	Rcpp::Rcout<<"Another way, sample::runif()(). Create the object, run the call operator and destorys the object"<<std::endl;
	for(int i = 0; i < Nrep; ++i){
		Rcpp::Rcout<<" "<<sample::runif()()<<" ||";
	}
	Rcpp::Rcout<<std::endl<<std::endl;

	Rcpp::Rcout<<"##########################"<<std::endl;
	Rcpp::Rcout<<"   Normal distribution   " <<std::endl;
	Rcpp::Rcout<<"##########################"<<std::endl;

	sample::rnorm 	  Norm;			  //create the object
	Rcpp::Rcout<<"Sequence using selected seed. N(1.0,0.5)"<<std::endl;
	for(int i = 0; i < Nrep; ++i){
		Rcpp::Rcout<<" "<<Norm(engine1,1.0,0.5)<<" ||";
	}
	Rcpp::Rcout<<std::endl<<std::endl;
	Rcpp::Rcout<<"Sequence using random seed. N(0,1) using default values"<<std::endl;
	for(int i = 0; i < Nrep; ++i){
		Rcpp::Rcout<<" "<<Norm()<<" ||";
	}
	Rcpp::Rcout<<std::endl<<std::endl;


	Rcpp::Rcout<<"##########################"<<std::endl;
	Rcpp::Rcout<<"   Gamma distribution    " <<std::endl;
	Rcpp::Rcout<<"##########################"<<std::endl;

	sample::rgamma 	  Gamma;			  //create the object
	Rcpp::Rcout<<"Sequence using random seed, defaulted engine."<<std::endl<<"Watch out notation, to get what we call Gamma(10,4) we have to call Gamma(10,0.25)"<<std::endl;
	for(int i = 0; i < Nrep; ++i){
		Rcpp::Rcout<<" "<<Gamma(10.0,0.25)<<" ||";
	}
	Rcpp::Rcout<<std::endl<<std::endl;
	
	Rcpp::Rcout<<"##########################"<<std::endl;
	Rcpp::Rcout<<" Chi-squared distribution " <<std::endl;
	Rcpp::Rcout<<"##########################"<<std::endl;

	sample::rchisq 	  Chisquared;			  //create the object
	Rcpp::Rcout<<"Sequence using random seed, defaulted engine."<<std::endl;
	for(int i = 0; i < Nrep; ++i){
		Rcpp::Rcout<<" "<<Chisquared(20.0)<<" ||";
	}
	Rcpp::Rcout<<std::endl<<std::endl;

	Rcpp::Rcout<<"##########################"<<std::endl;
	Rcpp::Rcout<<"  Dirichlet distribution  " <<std::endl;
	Rcpp::Rcout<<"##########################"<<std::endl;

	/*This is a template class. The template parameter may be defaulter to use VecCol*/
	int k = 5; //number of dirichelt components

	Rcpp::Rcout<<"Testing VecCol"<<std::endl;
	sample::rdirichlet<VecCol> 	Dir_veccol; 
	sample::rdirichlet<VecCol> 	Dir_veccol2; //same as before 

	VecCol alfa1 = VecCol::Constant(k,10.0); //alfa1[0]=alfa1[1]=alfa1[2]=10.0
	VecRow alfa2 = VecRow::Constant(k,10.0); 
	std::vector<double> alfa3(k, 10.0);
	MatCol alfa4 = MatCol::Constant(k,k,10.0);

	Rcpp::Rcout<<"The call operator is itself a templete method, I can call it both with VecCol and VecRow as input."<<std::endl;
	Rcpp::Rcout<<"Return VecCol, input VecCol: "<<std::endl;
	Rcpp::Rcout<< Dir_veccol(engine1, alfa1) <<std::endl;
	Rcpp::Rcout<<"Return VecCol, input VecRow: "<<std::endl;
	Rcpp::Rcout<< Dir_veccol(engine1, alfa2) <<std::endl;
	Rcpp::Rcout<<"Can not pass alfa as an std::vector<double>. You get the compiler error ‘std::vector<double>’ is not derived from ‘const Eigen::MatrixBase<Derived> "<<std::endl;
	//Rcpp::Rcout<< Dir_veccol(engine1, alfa3) <<std::endl;
	Rcpp::Rcout<<"However you can wrap the std::vector into an eigen type. Eigen::Map is extremely efficient, no overhead is introduced"<<std::endl;
	Rcpp::Rcout<< Dir_veccol(engine1, Eigen::Map<const VecCol> (&(alfa3[0]), alfa3.size()) ) <<std::endl;
	Rcpp::Rcout<<"It is difficult to check types. For examples, the function may be call passing a matrix. This is the danger of templates, the function works but it would produce an error."<<std::endl;
	//Rcpp::Rcout<< Dir_veccol(engine1, alfa4) <<std::endl;

	Rcpp::Rcout<<"----- Testing VecRow -------"<<std::endl;
	sample::rdirichlet<VecRow> 	Dir_vecrow; 

	Rcpp::Rcout<<"Return VecRow, input VecCol: "<<std::endl;
	Rcpp::Rcout<< Dir_vecrow(engine1, alfa1) <<std::endl;
	Rcpp::Rcout<<"Return VecRow, input VecRow: "<<std::endl;
	Rcpp::Rcout<< Dir_vecrow(engine1, alfa2) <<std::endl;
	Rcpp::Rcout<<"Return VecRow, input std::vector wrapped as Eigen:"<<std::endl;
	Rcpp::Rcout<< Dir_vecrow(engine1, Eigen::Map<const VecCol> (&(alfa3[0]), alfa3.size()) ) <<std::endl;

	Rcpp::Rcout<<"----- Testing std::vector<double> -------"<<std::endl;
	sample::rdirichlet<std::vector<double>> 	Dir_vector; 
	std::vector<double> theta_dir(k,0.0);

	Rcpp::Rcout<<"Return std::vector<double>, input VecCol: "<<std::endl;
	theta_dir = Dir_vector(engine1, alfa1);
		for(auto __v : theta_dir)
			std::cout<<__v<<", ";
		std::cout<<std::endl;
	Rcpp::Rcout<<"Return std::vector<double>, input VecRow: "<<std::endl;
	theta_dir = Dir_vector(engine1, alfa2);
		for(auto __v : theta_dir)
			std::cout<<__v<<", ";
		std::cout<<std::endl;
	Rcpp::Rcout<<"Return std::vector<double>, input std::vector wrapped as Eigen:"<<std::endl;
	theta_dir = Dir_vector(engine1, Eigen::Map<const VecCol> (&(alfa3[0]), alfa3.size()) );
		for(auto __v : theta_dir)
			std::cout<<__v<<", ";
		std::cout<<std::endl;


}

#endif