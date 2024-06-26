% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{calcola_stirling}
\alias{calcola_stirling}
\title{Compute Non Central C number - Direct formula Raf}
\usage{
calcola_stirling(n, gamma, r)
}
\description{
Compute the Charalambides non central C numbers using the direct formula, i.e the (2.60) one in the "Combinatorial methods in discrete distributions" book.
This version works for r and gamma real numbers, not only positive. However, it is unstable.
It computes the whole sequence, C(n,k,gamma,r) for k=0,...,n
}
