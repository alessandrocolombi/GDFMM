% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{build_logC_matrix}
\alias{build_logC_matrix}
\title{Build matrix of logC numbers}
\usage{
build_logC_matrix(n, k, s, r, res)
}
\description{
This is the recursive function called by \code{\link{my_logC}} that builds the matrix containing all the log(|C(n,k)|) numbers.
It gets as input the element (n,k) to build, the scale s and location r (here defined as positive and non-negative numbers) and the
matrix res to be build. The matrix is constructed diagonal by diagonal, starting from the bottom.
Important remark, note that log(|C(n,0)|) = log(raising factorial (n,r)).
}
