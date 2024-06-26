#include "RcppArmadillo.h"
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]

//' Rigon - lgfactorial
//'
//' @export
// [[Rcpp::export]]
arma::vec lgfactorial(int n, double sigma){
  
  arma::vec LogCk1(n+1); LogCk1.zeros();
  arma::vec LogCk(n+1);  LogCk.zeros();
  
  LogCk1(1) = std::log(sigma);
  LogCk1(0) = -arma::datum::inf;
  LogCk(0)  = -arma::datum::inf;
  
  for(int i = 2; i <= n; i++){
    LogCk(1)   = std::log(i - 1 - sigma) + LogCk1(1);
    for(int j = 2; j < i; j++){
        LogCk(j) = LogCk1(j-1)+ std::log(sigma + (i - 1 - sigma*j)*std::exp(LogCk1(j) - LogCk1(j-1)));
    }
    LogCk(i)  = i*std::log(sigma);
    LogCk1    = LogCk;
  }
  return(LogCk.rows(1,n));
}

//' Rigon - lgfactorials
//'
//' @export
// [[Rcpp::export]]
arma::mat lgfactorials(int n, double sigma){
  
  arma::mat LogC(n+1,n+1);  LogC.fill(-arma::datum::inf);
  
  // Fill the starting values
  LogC(0,0) = 0;
  LogC(1,1) = std::log(sigma);

  for(int i = 2; i <= n; i++){
    LogC(i,1)   = std::log(i - 1 - sigma) + LogC(i-1,1);
    for(int j = 2; j < i; j++){
      LogC(i,j) = LogC(i-1,j-1) + std::log(sigma + (i - 1 - sigma*j)*std::exp(LogC(i-1,j) - LogC(i-1,j-1)));
    }
    LogC(i,i)  = i*std::log(sigma);
  }
  return(LogC.submat(1,1,n,n));
}

//' Rigon - lgfactorial_ns
//'
//' @export
// [[Rcpp::export]]
arma::vec lgfactorial_ns(int n, double sigma){
  
  arma::vec LogCk1(n+1); LogCk1.zeros();
  arma::vec LogCk(n+1);  LogCk.zeros();
  
  double sigma_pos = - sigma;
  
  LogCk1(1) = std::log(sigma_pos);
  LogCk(0) = -arma::datum::inf;
  
  for(int i = 2; i <= n; i++){
    LogCk(1)   = std::log(i - 1 + sigma_pos) + LogCk1(1);
    for(int j = 2; j < i; j++){
      LogCk(j) = LogCk1(j-1)+ std::log(sigma_pos + (i - 1 + sigma_pos*j)*std::exp(LogCk1(j) - LogCk1(j-1)));
    }
    LogCk(i)  = i*std::log(sigma_pos);
    LogCk1    = LogCk;
  }
  return(LogCk.rows(1,n));
}

// This is not exported since it not used
arma::mat lgfactorials_ns(int n, double sigma){
  
  arma::mat LogC(n+1,n+1);  LogC.fill(-arma::datum::inf);
  
  double sigma_pos = - sigma;
  
  // Fill the starting values
  LogC(0,0) = 0;
  LogC(1,1) = std::log(sigma_pos);
  
  for(int i = 2; i <= n; i++){
    LogC(i,1)   = std::log(i - 1 + sigma_pos) + LogC(i-1,1);
    for(int j = 2; j < i; j++){
      LogC(i,j) = LogC(i-1,j-1) + std::log(sigma_pos + (i - 1 + sigma_pos*j)*std::exp(LogC(i-1,j) - LogC(i-1,j-1)));
    }
    LogC(i,i)  = i*std::log(sigma);
  }
  return(LogC.submat(1,1,n,n));
}

//' Rigon - lastirling1
//'
//' Commento Ale: questa fuzione restituisce il vettore contenente il logaritmo dell'intero sviluppo dei moduli di un
//' numero di Stirling del primo tipo. 
//' Per esempio, per n=4, ho |s(n,0)| = 0, |s(n,1)| = 6, |s(n,2)|= 11, |s(n,3)| = 6, |s(n,4)| = 4.
//' Quindi, lo sviluppo di 4 è un vettore di 4 elementi (lo 0 è banale, lo omettiamo) 
//' @export
// [[Rcpp::export]]
arma::vec lastirling1(int n){
  
  arma::vec LogSk1(n+1); LogSk1.zeros();
  arma::vec LogSk(n+1);  LogSk.zeros();
  
  LogSk1(1) = 0;
  LogSk1(0) = -arma::datum::inf;
  LogSk(0)  = -arma::datum::inf;
  
  for(int i = 2; i <= n; i++){
    for(int j  = 1; j < i; j++){
      LogSk(j) = LogSk1(j) + std::log(i - 1 + std::exp(LogSk1(j-1) - LogSk1(j)));
    }
    LogSk(i)  = 0;
    LogSk1    = LogSk;
  }
  return(LogSk.rows(1,n));
}

//' Rigon - lastirlings1
//'
//' Commento Ale, questa è l'estensione di lastirling1. Questa ritorna una matrice triangolare inferiori, l'argomento n
//' vuol dire che deve calcolare tutti gli sviluppi fino ad n, partendo da s(1) che è banalmente uguale ad uno. Anche
//' questa lavora in scala logaritmica.
//' @export
// [[Rcpp::export]]
arma::mat lastirlings1(int n){
  
  arma::mat LogS(n+1,n+1);  LogS.fill(-arma::datum::inf);
  
  // Fill the starting values
  LogS(0,0) = 0;
  LogS(1,1) = 0;
  
  for(int i = 2; i <= n; i++){
    for(int j = 1; j < i; j++){
      LogS(i,j) = LogS(i-1,j) + std::log(i-1 + std::exp(LogS(i-1,j-1) - LogS(i-1,j))); 
    }
    LogS(i,i)  = 0;
  }
  return(LogS.submat(1,1,n,n));
}