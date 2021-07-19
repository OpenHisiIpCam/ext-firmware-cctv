# Build configurations

## Types

* `generic_chip_defconfig` - Default SoC system.
* `vendor_model_bsp_defconfig` - Full empty system for some board.
* `toolchain_family_libc_defconfig` - SDK/Toolchain.

## Generic build

**TODO** add notes.

For boards configurations handling we use config managment system built on top of buildroot's defconfigs.
This managment system basicly build defconfig file from set of config fragments.

Merge is done by [merge_config_plus](../tools/merge_config_plus/README.md) utility.

High level fragments are located in `../boards/[vendor]/[model]` directories, named `*.br.config`.

## Build

```console
$ make
$ ls
```

## Fragments organization

## Notes 
