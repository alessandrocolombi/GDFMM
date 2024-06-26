% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/GDFMM_export.R
\name{set_options_marginal}
\alias{set_options_marginal}
\title{set_options_marginal}
\usage{
set_options_marginal(
  partition = NULL,
  Lambda0 = 3,
  mu0 = 0,
  sigma0 = 1,
  gamma0 = NULL,
  UseData = TRUE,
  Adapt_MH_hyp1 = 0.7,
  Adapt_MH_hyp2 = 0.234,
  sp_mala_U = 0.01,
  sp_mala_gamma = 0.01,
  k0 = 1/10,
  nu0 = 10,
  alpha_gamma = 1,
  beta_gamma = 1,
  alpha_lambda = 1,
  beta_lambda = 1,
  init_mean_cluster = NULL,
  init_var_cluster = NULL,
  UpdateU = T,
  UpdateGamma = T,
  UpdateTau = T,
  UpdateLambda = T
)
}
\arguments{
\item{partition}{\link{vector} of length equal to the number of data. If \code{NULL}, all data points are put in the same cluster.}

\item{Lambda0}{\link{double} the initial value for Lambda.}

\item{mu0}{\link{double} the mean parameter in the prior of mu.}

\item{sigma0}{\link{double} the rate parameter in the prior of sigma.}

\item{gamma0}{\link{vector} of initial values for the gamma parameters.}

\item{UseData}{\link{bool} set \code{FALSE} to sample from the prior.}

\item{Adapt_MH_hyp1}{\link{double} default is 0.7.}

\item{Adapt_MH_hyp2}{\link{double} default is 0.234.}

\item{k0}{\link{double} the parameter in the prior of mu.}

\item{nu0}{\link{double} the shape parameter in the prior of sigma.}

\item{alpha_gamma}{\link{double} the shape parameter in the prior of gamma.}

\item{beta_gamma}{\link{double} the rate parameter in the prior of gamma.}

\item{alpha_lambda}{\link{double} the shape parameter in the prior of lambda.}

\item{beta_lambda}{\link{double} the rate parameter in the prior of lambda.}

\item{UpdateU}{\link{bool} set \code{TRUE} if U must be updated. Set \code{FALSE} to fix it to a common value.}

\item{UpdateGamma}{\link{bool} set \code{TRUE} if gamma must be updated. Set \code{FALSE} to fix it to a common value.}

\item{UpdateTau}{\link{bool} set \code{TRUE} if tau must be updated. Set \code{FALSE} to fix it to a common value.}

\item{UpdateLambda}{\link{bool} set \code{TRUE} if Lambda must be updated. Set \code{FALSE} to fix it to a common value.}
}
\description{
Use this function to set up the options for the conditional Gibbs sampler.
}
