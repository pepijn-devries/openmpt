#' Get a specific ModPlug pattern table
#' 
#' TODO
#' @param mod A tracker module object of class `openmpt`.
#' @param width TODO
#' @param pad TODO
#' @param ... Ignored
#' @returns A `matrix` of pattern cells formatted as `character` strings. Each column represents
#' an audio channel.
#' @examples
#' # TODO
#' @export
pattern <- function(mod, pattern = 0L, width = 0L, pad = TRUE, ...) {
  format_pattern_(mod, as.integer(pattern), width, pad)
}
