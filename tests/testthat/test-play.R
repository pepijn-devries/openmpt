mod <- demo_mod()

test_that("Audio plays if audio device is present", {
  expect_true({
    sink(tempfile())
    result <-
      if (has_audio_device()) {
        success <- tryCatch({
          play(mod, duration = 1, progress = "none")
          TRUE
        }, error = function(e) FALSE)
      } else {
        TRUE
      }
    sink()
    result
  })
})

test_that("Progress report throws no errors", {
  expect_no_error({
    openmpt:::test_omt_progress(mod, "none")
    openmpt:::test_omt_progress(mod, "time")
    openmpt:::test_omt_progress(mod, "vu")
  })
})

rm(mod)