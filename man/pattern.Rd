% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/pattern.R
\name{pattern}
\alias{pattern}
\alias{format_pattern_row_channel}
\alias{format_pattern_row_channel_command}
\alias{highlight_pattern_row_channel}
\alias{highlight_pattern_row_channel_command}
\title{Get a specific \code{openmpt} pattern table or its cells}
\usage{
pattern(mod, pattern = 0L, width = 0L, pad = TRUE, ...)

format_pattern_row_channel(mod, pattern, row, channel, width, pad, ...)

format_pattern_row_channel_command(mod, pattern, row, channel, command, ...)

highlight_pattern_row_channel(mod, pattern, row, channel, width, pad, ...)

highlight_pattern_row_channel_command(mod, pattern, row, channel, command, ...)
}
\arguments{
\item{mod}{A tracker module object of class \code{openmpt}.}

\item{pattern}{The pattern index (starting at \code{0}) of the pattern to get.}

\item{width}{The maximum number of characters the string should contain. \code{0} means no limit.}

\item{pad}{If \code{TRUE}, the string will be resized to the exact length provided in the width parameter.}

\item{...}{Ignored}

\item{row}{A row index (starting at \code{0}) for the row inside the pattern table.}

\item{channel}{a channel (i.e., column) index (starting at \code{0}) inside the pattern table.}

\item{command}{One of \code{"note"}, \code{"instrument"}, \code{"volumeffect"}, \code{"effect"}, \code{"volume"}, or
\code{"parameter"}.}
}
\value{
A \code{matrix} of pattern cells formatted as \code{character} strings in case of \code{pattern()}.
Each column represents. All other methods return a single string for a specific cell.
an audio channel.
}
\description{
Collects a specific pattern table from a tracker module and presents it as
a matrix of formatted \code{character} strings in case of \code{pattern()}. The other
functions return a single string for a specific cell inside the pattern table.
}
\examples{
mod <- demo_mod()
pattern(mod)
format_pattern_row_channel(mod, 0L, 1L, 2L, 0L, TRUE)
format_pattern_row_channel_command(mod, 0L, 1L, 2L, "parameter")
highlight_pattern_row_channel(mod, 0L, 1L, 2L, 0L, TRUE)
highlight_pattern_row_channel_command(mod, 0L, 1L, 2L, "note")
}
