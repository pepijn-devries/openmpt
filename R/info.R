#' TODO
#' 
#' TODO
#' @param key TODO
#' @param ... Ignored
#' @returns TODO
#' @examples
#' # TODO
#' @export
get_string <- function(key = "library_version", ...) {
  lompt_get_string_(key)
}

#' Get ModPlug Tracker module meta data
#' 
#' TODO
#' @param mod A tracker module object of class `openmpt`.
#' @param key TODO
#' @param ... Ignored
#' @returns TODO
#' @examples
#' # TODO
#' @export
get_metadata <- function(mod, key = "title", ...) {
  get_metadata_(mod, key)
}

#' Get ModPlug Tracker module duration
#' 
#' TODO
#' @param mod A tracker module object of class `openmpt`.
#' @param ... Ignored
#' @returns TODO
#' @examples
#' # TODO
#' @export
get_duration_seconds <- function(mod, ...) {
  get_duration_seconds_(mod)
}