# Merge config plus (Kconfig defconfig preprocessor)

Tool for Kconfig's config fragments merge inspired by `merge_config.sh`, extending it's capabilities.

Kconfig itself has [macro language](https://www.kernel.org/doc/html/latest/kbuild/kconfig-macro-language.html),
but this is macro language for defconfigs preprocessing.

**Current status: functional prototype.**

## Features

* `=` create new var or replace old value with new
* `include`, `oinclude` include config fragment to the flow
* `+=`, `=+` append or prepend value for previous (for string vars)
* ~`$(NAME)` replace with existing var value immidiately~
* ~`${NAME}` replace with existing var value at the end of processing~
* $(ROOT) replace with predefine var value immidiately
* `-=` remove substring from existing string value

## Usage

```console
$ ./merge_config_plus.py --help
usage: merge_config_plus.py [-h] [-v] [--version] [-r ROOT] [-o OUTPUT]
                            [--strip-strings] [--disable-history]
                            F [F ...]

Kconfig defconfig preprocessor.

positional arguments:
  F                     Files list

optional arguments:
  -h, --help            show this help message and exit
  -v, --verbose         Print debug output (default: False)
  --version             show program's version number and exit
  -r ROOT, --root ROOT  Root directory (default: /home/nikita/ohic/REPO/bsp-
                        initial/tools/merge_config_plus)
  -o OUTPUT, --output OUTPUT
                        Output to file (default: -)
  --strip-strings       Strip final string values (default: False)
  --disable-history     Remove var values history from output (default: False)
```

## TODO and ideas

* use makefile macro language $(func arg1,arg2,...)
  * $(var NAME) or $(NAME)
  * $(include FILE), $(-include FILE)
  * $(if var,if-y,if-n)
* some feature for prev values cleanup / is not set means remove
* macroses can be nested
* trim strings option
* predefined vars option (like ROOT)
* output comments to final defconfig
* validate deconfig via kconfig, use https://pypi.org/project/kconfiglib !!!!
* improve overall output human visual inspection log
  * string manipulations seems are not clear
