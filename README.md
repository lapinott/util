# `util::`

## a small collection of utility code
- `filesystem_path_t`

    Cross-platform filesystem path with automatic utf8 <-> utf16 conversion on Windows. Used by zipfs.

- `split.h`

    std::string split. Used by zipfs.

- `utf8_utf16_conv.h`

    utf8 <-> utf16 conversion on Windows. *Not yet implemented for \*nix & macos*. Used by `filesystem_path_t`.

## requirements
- C++ 17

## dependencies

- boost (only the `boost::filesystem::operations` header)

## build instructions

- Download & build [`boost`](https://www.boost.org/). The part we need (`boost::filesystem`) is not header-only so we will have to compile it. Instructions can be found [here](https://www.boost.org/doc/libs/1_78_0/more/getting_started/index.html).
- Generate the build solution with CMAKE. You will have to tell CMAKE where to look for the *boost dir*.
- Build.

## license
(c) 2022 Julien Matthey - Released under the MIT license. Some code is copy-pasted from stackoverflow.com - please see header files.