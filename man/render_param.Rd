% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/controls.R
\name{render_param}
\alias{render_param}
\alias{render_param<-}
\title{Get or set render parameters for a specific module}
\usage{
render_param(mod, key, ...)

render_param(mod, key, ...) <- value
}
\arguments{
\item{mod}{A tracker module object of class \code{openmpt}.}

\item{key}{One of \code{"MASTERGAIN"}, \code{"STEREOSEPARATION"}, \code{"INTERPOLATION"}, or \code{"VOLUMERAMPING"}.
details copied from libopenmpt
\href{https://lib.openmpt.org/doc/classopenmpt_1_1module.html#ab4ae2823cb180657142f5f1a93cd64aa}{documentation}
\describe{
\item{Master Gain}{
The related value represents a relative gain in milliBel.
The default value is 0. The supported value range is unlimited.
}
\item{Stereo Separation}{
The related value represents the stereo separation generated by the libopenmpt mixer in percent.
The default value is 100. The supported value range is from 0 up to 200.
}
\item{Interpolation Filter}{
The related value represents the interpolation filter length used by the libopenmpt mixer.
The default value is 0, which indicates a recommended default value.
The supported value range is from 0 up to infinity. Values greater than the implementation
limit are clamped to the maximum supported value.
Currently supported values:
\itemize{
\item 0: internal default
\item 1: no interpolation (zero order hold)
\item 2: linear interpolation
\item 4: cubic interpolation
\item 8: windowed sinc with 8 taps
}
}
\item{Volume Ramping Strength}{
The related value represents the amount of volume ramping done by the libopenmpt mixer.
The default value is -1, which indicates a recommended default value.
The meaningful value range is from -1 up to 10.
A value of 0 completely disables volume ramping. This might cause clicks in sound output.
Higher values imply slower/softer volume ramps.
}
}}

\item{...}{Ignored.}

\item{value}{An \code{integer} replacement value for the render parameter selected with \code{key}}
}
\value{
Returns the current integer render parameter for the specified
\code{key} and \code{mod}. In case of an assign operator (\verb{<-}) \code{mod} with an updated
set of render parameters is returned.
}
\description{
Each individual module has its own set of render parameters. Use these functions
to obtain or set the state of these parameters.
}
\examples{
mod <- demo_mod()

render_param(mod, "STEREOSEPARATION") <- 50
render_param(mod, "STEREOSEPARATION")
render_param(mod, "MASTERGAIN")
render_param(mod, "INTERPOLATION")
render_param(mod, "VOLUMERAMPING")
}
