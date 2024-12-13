#' Format a cell in a pattern table as text
#' 
#' TODO
#' 
#' @seealso [pattern()]
#' @param mod A tracker module object of class `openmpt`.
#' @param pattern TODO
#' @param row TODO
#' @param channel TODO
#' @param width TODO
#' @param pad TODO
#' @param command One of `"note"`, `"instrument"`, `"volumeffect"`, `"effect"`, `"volume"`, or
#' `"parameter"`.
#' @param ... Ignored
#' @returns TODO
#' @examples
#' mod <- demo_mod()
#' format_pattern_row_channel(mod, 0L, 1L, 2L, 0L, TRUE)
#' format_pattern_row_channel_command(mod, 0L, 1L, 2L, "parameter")
#' highlight_pattern_row_channel(mod, 0L, 1L, 2L, 0L, TRUE)
#' highlight_pattern_row_channel_command(mod, 0L, 1L, 2L, "note")
#' # TODO
#' @rdname format
#' @export
format_pattern_row_channel <- function(mod, pattern, row, channel, width, pad, ...) {
  format_pattern_row_channel_(mod, as.integer(pattern), as.integer(row), as.integer(channel),
                              as.integer(width), as.logical(pad))
}

#' @rdname format
#' @export
format_pattern_row_channel_command <- function(mod, pattern, row, channel, command, ...) {
  format_pattern_row_channel_command_(mod, as.integer(pattern), as.integer(row),
                                      as.integer(channel), .command_to_index(command))
}

#' @rdname format
#' @export
highlight_pattern_row_channel <- function(mod, pattern, row, channel, width, pad, ...) {
  highlight_pattern_row_channel_(mod, as.integer(pattern), as.integer(row), as.integer(channel),
                                 as.integer(width), as.logical(pad))
}

#' @rdname format
#' @export
highlight_pattern_row_channel_command <- function(mod, pattern, row, channel, command, ...) {
  highlight_pattern_row_channel_command_(mod, as.integer(pattern), as.integer(row),
                                         as.integer(channel), .command_to_index(command))
}

.command_to_index <- function(command) {
  pmatch(
    command,
    c("note", "instrument", "volumeffect", "effect", "volume", "parameter")
  ) - 1L
}
