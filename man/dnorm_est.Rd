% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/GDFMM_export.R
\name{dnorm_est}
\alias{dnorm_est}
\title{dnorm_est : compute the point-wise estimate of the density for points in the given grid.
mu_vec e sigma_vec are respectively the vector of means and standard deviation
estimate for the gaussian distribution}
\usage{
dnorm_est(grid, mu_vec, sigma_vec, alpha = 0.05)
}
\arguments{
\item{grid}{vector of point where I want to evaluate the density}

\item{mu_vec}{vector of mean for the gaussian distribution}

\item{sigma_vec}{vector of standard deviation for the gaussian distribution}

\item{alpha}{level of confidence}
}
\value{
named matrix with (Inf, estimate, Sup)
}
\description{
dnorm_est : compute the point-wise estimate of the density for points in the given grid.
mu_vec e sigma_vec are respectively the vector of means and standard deviation
estimate for the gaussian distribution
}
