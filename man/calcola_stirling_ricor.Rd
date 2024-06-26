% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{calcola_stirling_ricor}
\alias{calcola_stirling_ricor}
\title{Compute Non Central C number - Recursive formula Raf}
\usage{
calcola_stirling_ricor(n, gamma, r)
}
\description{
Compute the Charalambides non central C numbers using the recursive formula, i.e the (2.67) one in the "Combinatorial methods in discrete distributions" book.
This version works for r and gamma real numbers, not only positive. However, it is not in log scale, therefore its usage is limited to small n cases.
It computes the whole sequence, C(n,k,gamma,r) for k=0,...,n.
}
