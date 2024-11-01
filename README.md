
# openmpt

<!-- badges: start -->
<!-- TODO add when system-requirements are available in workflow
[![R-CMD-check](https://github.com/pepijn-devries/openmpt/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/pepijn-devries/openmpt/actions/workflows/R-CMD-check.yaml)
-->
<!-- badges: end -->

<img src="man/figures/logo.svg" align="right" height="139" copyright="cc-sa" alt="logo" class="pkgdown-hide" />

An [OpenMPT](https://www.openmpt.org) port for `R`. It reads, plays and
converts Open ModPlug Tracker music. It supports a wide range of music
[file formats](https://wiki.openmpt.org/Manual:_Module_formats).

## Installation

<!-- TODO check if installation works with r-system-requirements-->

``` r
# install.packages("devtools")
devtools::install_github("pepijn-devries/openmpt")
```

On Debian/Ubuntu you need to install the developer version of libopenmpt
and portaudio first:

``` sh
sudo apt-get install libopenmpt-dev portaudio19-dev
```

And on Fedora you need:

``` sh
sudo dnf install libopenmpt-devel portaudio-devel
```

On RHEL/CentOS/RockyLinux you first need to enable EPEL:

``` sh
yum install -y epel-release
sudo yum install libopenmpt-dev portaudio19-dev
```

## Example

You only need 3 lines of code to load the library, read a module and
play it:

``` r
library(openmpt)

mod <- demo_mod()

play(mod)
```

## Code of Conduct

Please note that the openmpt project is released with a [Contributor
Code of
Conduct](https://contributor-covenant.org/version/2/1/CODE_OF_CONDUCT.html).
By contributing to this project, you agree to abide by its terms.
