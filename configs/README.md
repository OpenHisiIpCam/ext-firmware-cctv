# Configs

Config here is Buildroot's configuration targeted to build full system 
(and optionally pack it to firmware image and OTA) for particular hardware model. 

TODO
Configuration is presented in form of
difference between default and target variables list. 
Such difference is named defconfig (files with suffix `_defconfig`).

Configs are not stored in repo, but are generated dynamicly from sources.

If there are no `*_defconfig` files, build them.

```console
user@host:~/cctv/configs$ make
...
mcp [INFO]: Processing to 'hisilicon_hi3536dv100_hi3536dv100_defconfig' done
mcp [INFO]: Processing to 'hisilicon_hi3536dv100_toolchain-uclibc_defconfig' done
mcp [INFO]: Processing to 'hisilicon_hi3516av200_hi3519v101_defconfig' done
...
```

You can find three config types:

1. `vendor_family_toolchain-lib_defconfig` - toolchain package for particular chips family.
2. `vendor_family_chip_defconfig` - particular chip base system, not targetted any real hardware.
3. `vendor_model_type_defconfig` - system for real hardware model, where `type` is system's purpose. 

**TODO**

## Config's compose

### Overview

Buildroot is based on Kbuild build system, that is configured via Kconfig language.

Some components are themselfs based on Kbuild and require it's own Kconfig configs.
Such components are for example Linux kernel, U-Boot or Busybox. 
In this case Buildroot's config store file pathe to component's config
and forward it to component's build system.

 
In case of legacy U-Boot's versions, it is not possible to configure them
outside of it's source tree. In such case patches over sources required.

Finally we come to the conclusion that a config is a set of consistent configs and patches.
It is possible to highlight common parts ...

###

Configs generation system is built using 
[merge_config_plus](https://github/OpenHisiIpCam/merge_config_plus) tool.
System here is config fragment files (sources) collection, 
that are orginized, named and composed according convention.

Typical config compose process:
**PUT IMAGE HERE**


