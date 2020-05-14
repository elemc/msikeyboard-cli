msikeyboard-cli
===============

[![Copr build status](https://copr.fedorainfracloud.org/coprs/elemc/msikeyboard/package/msikeyboard-cli/status_image/last_build.png)](https://copr.fedorainfracloud.org/coprs/elemc/msikeyboard/package/msikeyboard-cli/)

Command line interface application for change colors, intensity and mode on MSI laptop keyboards (and logos).

Dependencies:
* libmsikeyboard (C library) https://github.com/elemc/libmsikeyboard
* boost (C++ library, program_options) https://www.boost.org/
* hidapi (C library) https://github.com/signal11/hidapi
* meson build system https://mesonbuild.com/
* or cmake https://cmake.org/
* C++ compiler with support standard C++11
* systemd support (if you use meson) https://www.freedesktop.org/wiki/Software/systemd/

 RPM packages for EPEL and Fedora https://copr.fedorainfracloud.org/coprs/elemc/msikeyboard/