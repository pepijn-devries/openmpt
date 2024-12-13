#' TODO
#' @examples
#' ## These examples are wrapped in `tryCatch`
#' ## as they attempt to access online resources
#'
#' tryCatch({
#'   mod_info <- modarchive_info(41529)
#'   if (!is.null(mod_info)) mod_info$modarchive$module$url[[1]]
#'   elekfunk <- modarchive_download(41529)
#'   search_results <- modarchive_search_mod("*_-_intro.mod",
#'                                           size = "0-99",
#'                                           format = "MOD")
#' })
#' 
#' @rdname modarchive_download
#' @export
modarchive_info <- function(mod_id, api = Sys.getenv("MODARCHIVE_API")) {
  mod_id      <- as.integer(mod_id[[1]])
  api         <- .check_api(api)
  result      <- NULL
  
  if (api != "" && .check_namespace()) {
    result <-
      .try_online({
        httr2::request(.modarchive_tool) |>
          httr2::req_url_query(
            key     = api,
            request = "view_by_moduleid",
            query   = mod_id
          ) |>
          httr2::req_perform()
      })
    if (!is.null(result)) {
      result <- result |>
        httr2::resp_body_xml() |>
        xml2::as_list()
    }
  }
  return(result)
}

#' @rdname modArchive
#' @export
modarchive_download <- function(mod_id, read_fun = read_mod, ...)
{
  mod_id <- as.integer(mod_id[[1]])
  url <- paste0("https://api.modarchive.org/downloads.php?moduleid=", mod_id)
  read_fun(url, ...)
}

#' @rdname modArchive
#' @export
modarchive_search_mod <- function(
    text,
    where = c("filename_or_songtitle", "filename_and_songtitle", "filename",
              "songtitle", "module_instruments", "module_comments"),
    format = c("unset", "669", "AHX", "DMF", "HVL", "IT", "MED", "MO3",
               "MOD", "MTM", "OCT", "OKT", "S3M", "STM", "XM"),
    size = c("unset", "0-99", "100-299", "300-599", "600-1025",
             "1025-2999", "3072-6999", "7168-100000"),
    page,
    api = Sys.getenv("MODARCHIVE_API")
) {
  api         <- .check_api(api)
  where       <- match.arg(where)
  format      <- match.arg(format)
  size        <- match.arg(size)
  if (format == "unset") format <- NULL
  if (size   == "unset")   size <- NULL
  if (missing(page))       page <- NULL
  if(!is.null(page))       page <- as.integer(page[[1]])
  result      <- NULL
  
  if (api != "" && .check_namespace()) {
    browser() #TODO
    result <-
      .try_online({
        httr2::request(.modarchive_tool) |>
          httr2::req_url_query(
            key     = api,
            request = "search",
            query   = text,
            type    = where,
            format  = format,
            size    = size,
            page    = page
          ) |>
          httr2::req_perform()
      })
    if (!is.null(result)) {
      browser() #TODO
      result <- result |>
        httr2::resp_body_xml() |>
        xml2::as_list()
    }
  }
#  paste0("https://api.modarchive.org/xml-tools.php?key=",
         #                     api.key,
         #                     "&request=search&query=",
         #                     search.text,
         #                     "&type=",
         #                     search.where)
         #   if (format.filter != "unset") xmlcode <- paste0(xmlcode, "&format=",  format.filter)
         #   if (genre.filter  != "unset") xmlcode <- paste0(xmlcode, "&genreid=", genre.filter)
         #   if (size.filter   != "unset") xmlcode <- paste0(xmlcode, "&size=",    size.filter)
         #   if (!missing(page)) xmlcode <- paste0(xmlcode, "&page=", as.integer(page[[1]]))
}

# modArchive.search.mod <- function(search.text,
#                                   search.where  = c("filename_or_songtitle", "filename_and_songtitle", "filename", "songtitle", "module_instruments", "module_comments"),
#                                   format.filter = c("unset", "669", "AHX", "DMF", "HVL", "IT", "MED", "MO3", "MOD", "MTM", "OCT", "OKT", "S3M", "STM", "XM"),
#                                   size.filter   = c("unset", "0-99", "100-299", "300-599", "600-1025", "1025-2999", "3072-6999", "7168-100000"),
#                                   genre.filter = "deprecated",
#                                   page,
#                                   api.key)
# {
#   search.text   <- utils::URLencode(as.character(search.text[[1]]))
#   search.where  <- match.arg(search.where)
#   format.filter <- match.arg(format.filter)
#   size.filter   <- match.arg(size.filter)
#   api.key       <- as.character(api.key[[1]])
#   if (!missing(genre.filter)) warning("Argument 'genre.filter' is deprecated in this function and not used since ProTrackR version 0.3.4. Use 'modArchive.view.by' to browse modules by genre.")
#   
#   xmlcode <- paste0("https://api.modarchive.org/xml-tools.php?key=",
#                     api.key,
#                     "&request=search&query=",
#                     search.text,
#                     "&type=",
#                     search.where)
#   if (format.filter != "unset") xmlcode <- paste0(xmlcode, "&format=",  format.filter)
#   if (genre.filter  != "unset") xmlcode <- paste0(xmlcode, "&genreid=", genre.filter)
#   if (size.filter   != "unset") xmlcode <- paste0(xmlcode, "&size=",    size.filter)
#   if (!missing(page)) xmlcode <- paste0(xmlcode, "&page=", as.integer(page[[1]]))
#   result <- .get.module.table(xmlcode, "module")
#   return(result)
# }

.modarchive_tool <- "https://api.modarchive.org/xml-tools.php"