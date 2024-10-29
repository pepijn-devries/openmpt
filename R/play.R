#' Play a ModPlug Tracker module
#' 
#' Renders a module tracker object of class `openmpt` and plays it instantaneously.
#' @param mod A tracker module object of class `openmpt`.
#' @param sample_rate Output sample rate when playing the module.
#' @param progress Progress printed to console while playing. Should be one of
#' `"vu"` (indicative volume meter), `"time"` (shows timer) or `"none"` (don't show progress).
#' If your audio is stuttering you might want to set this to `"none"` to save processing speed.
#' @param ... Ignored
#' @returns Returns `NULL` invisibly.
#' @examples
#' \dontrun{
#' mod <- demo_mod()
#' play(mod)
#' }
#' @export
play <- function(mod, sample_rate = 44100L, progress = "vu", ...) {
  progress <- match.arg(progress, c("vu", "time", "none"))
  play_(mod, sample_rate, progress) |> invisible()
}
