#' Play a ModPlug Tracker module
#' 
#' TODO
#' @param mod A tracker module object of class `openmpt`.
#' @param sample_rate Output sample rate when playing the module.
#' @param ... Ignored
#' @returns `NULL`
#' @examples
#' \dontrun{
#' mod <- read_mod("https://api.modarchive.org/downloads.php?moduleid=41529#elektric_funk.mod")
#' play(mod)
#' }
#' @export
play <- function(mod, sample_rate = 44100L, ...) {
  play_(mod, sample_rate)
}
