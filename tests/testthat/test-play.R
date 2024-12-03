test_that("Audio plays if audio device is present", {
  expect_true({
    mod <- demo_mod()
    sink(tempfile())
    success <- tryCatch({
      play(mod, duration = 1)
      TRUE
    }, error = function(e) FALSE)
    sink()
    success == has_audio_device()
  })
})