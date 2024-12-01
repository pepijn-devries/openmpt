#' Get or set OpenMPT module controls
#' 
#' Each individual module has its own set of control variables. Use these functions
#' to obtain or set the state of these variables.
#' @param mod A tracker module object of class `openmpt`.
#' @param key A `character` string representing a specific control you whish to get or set.
#' Use `control_keys()` to list all available keys.
#' @param ... Ignored
#' @param value A replacement value for the specified control `key`. Check the
#' libopenmpt [documentation](https://buildbot.openmpt.org/builds/latest-unpacked/libopenmpt-docs/docs/classopenmpt_1_1module.html#a4870472969da4d659c5cc394bb1ed245)
#' for the appropriate replacement types and values for each of the `key` values.
#' @returns `control_keys()` returns a `vector` of strings containing all available
#' control keys for `mod`. `control()` returns the value for the specified `key'.
#' In case of an assign operator (`<-`) an updated version of `mod` is
#' returned, where the control key has been set if successful.
#' @examples
#' mod <- demo_mod()
#' control_keys(mod)
#' 
#' control(mod, "play.at_end")
#' control(mod, "play.at_end") <- "stop"
#' @rdname controls
#' @export
control_keys <- function(mod, ...) {
  get_ctls_(mod)
}

#' @rdname controls
#' @export
control <- function(mod, key, ...) {
  ctl_get_(mod, key)
}

#' @rdname controls
#' @export
`control<-` <- function(mod, key, ..., value) {
  ctl_set_(mod, key, value)
}