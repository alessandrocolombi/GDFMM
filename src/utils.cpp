#include "utils.h"

namespace utils{


	//double raising_factorial(const unsigned int& n, const double& a)
	//{
		//return( gsl_sf_poch(a, (double)n ) );
	//}
//
	//double my_falling_factorial(const unsigned int& n, const double& a)
//	//{
		//if(n%2 == 0) //n is even
			//return( gsl_sf_poch(-a, (double)n ) );
		//else //n is odd, change sign
			//return( -1*gsl_sf_poch(-a, (double)n ) );
	//}
//
	//double compute_Pochhammer(const unsigned int& x, const double& a)
	//{
		//return( gsl_sf_poch(a,x ) );
	//}
//
	//void build_logC_matrix(const unsigned int& n, const unsigned int& k, const double& s, const double& r, MatCol& res){
//
//std::cout<<"Costruisco n = "<<n<<", k = "<<k<<std::endl;
		//if(k>n)
			//throw std::runtime_error("Can not call build_logC_matrix if k > n");
//
		//// Boundary conditions
		//if(n == 0 && k == 0)
			//res(n,k) = 0;
		//else if(k == 0) 
			//res(n,k) = 1 + utils::my_falling_factorial(n,r);
		//else if(n == k){
			//build_logC_matrix(n-1, k-1, s, r, res);
			//res(n,k) = std::log(s) + res(n-1,k-1);
		//}
		////if(res(n,k)!= Eigen::Infinity)
			////return res(n,k);
		//else{
			//double coef(s*k + r + n - 1);
//
			////build_logC_matrix(n-1,k,s,r,res); // this has been already built for sure
			//build_logC_matrix(n-1,k-1,s,r,res); // the matrix is always constructed diagonal by diagonal
			//res(n,k) = std::log(coef) + res(n-1,k) + std::log( 1 + s/coef * std::exp( res(n-1,k-1) - res(n-1,k) ) );
			////return( std::log(coef) + build_logC_matrix(n-1,k,s,r,res) + std::log(1 + s/coef * std::exp(build_logC_matrix(n-1,k-1,s,r,res) - build_logC_matrix(n-1,k,s,r,res) )) );
			//// forse devo fare
			//// res(n,k) = std::log(coef) + build_logC_matrix(n-1,k,s,r,res) + std::log(1 + s/coef * std::exp(build_logC_matrix(n-1,k-1,s,r,res) - build_logC_matrix(n-1,k,s,r,res) ));
			//// return res(n,k);
		//}
//
	//}	







}
