#' Get a specific ModPlug pattern table
#' 
#' Collects a specific pattern table from a tracker module and presents it as
#' a matrix of formatted `character` strings.
#' @param mod A tracker module object of class `openmpt`.
#' @param pattern The pattern index (starting at `0`) of the pattern to get.
#' @param width The maximum number of characters the string should contain. `0` means no limit.
#' @param pad If `TRUE`, the string will be resized to the exact length provided in the width parameter.
#' @param ... Ignored
#' @returns A `matrix` of pattern cells formatted as `character` strings. Each column represents
#' an audio channel.
#' @examples
#' mod <- demo_mod()
#' pattern(mod)
#' @export
pattern <- function(mod, pattern = 0L, width = 0L, pad = TRUE, ...) {
  format_pattern_(mod, as.integer(pattern), width, pad)
}
