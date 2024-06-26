% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/GDFMM_export.R
\name{predictive}
\alias{predictive}
\title{predictive}
\usage{
predictive(idx_group, grid, fit, burnin = 1)
}
\arguments{
\item{idx_group}{\link{integer} the index of the group of interest.}

\item{grid}{\link{vector} a grid where the normal kernel is evaluated.}

\item{fit}{\link{list} the output of a conditional sampler, \code{\link{GDFMM_sampler}} or \code{\link{ConditionalSampler}}}

\item{burnin}{\link{integer} the number of draws from \code{\link{GDFMM_sampler}} that must be discarded.}
}
\value{
\link{matrix} of size \code{n x length(grid)} containing the quantiles of level \code{0.025,0.5,0.975}.
}
\description{
This function computes the predictive distribution for group \code{idx_group} generated from the \code{\link{GDFMM_sampler}} or \code{\link{ConditionalSampler}}
}
