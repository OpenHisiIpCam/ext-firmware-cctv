# Buildroot scripts

Here stored scripts that are invoked by BR via external.mk.

## 123

```
.
├── genimage.sh
├── hisi-uboot-add-regbin.sh
├── libscripts.sh
├── swupdate.sh
└── system.sh
```

## Data passed to script invoked via MK
```
BR2_EXTERNAL_CCTV_PATH=/mnt/storage/nikita/CAMERA/bsp-initial
BR2_EXTERNAL_CCTV_DESC=CCTV firmware
OLDPWD=/mnt/storage/nikita/CAMERA/bsp-initial/output/xm_53h20-s_bsp/build
BUILDROOT_CONFIG=/tmp/deprecated/The-BUILDROOT_CONFIG-environment-variable-was-renamed-to-BR2_CONFIG
BR2_REPRODUCIBLE=
BASE_DIR=/mnt/storage/nikita/CAMERA/bsp-initial/output/xm_53h20-s_bsp
STAGING_DIR=/mnt/storage/nikita/CAMERA/bsp-initial/output/xm_53h20-s_bsp/host/arm-hi3516cv100-linux-uclibcgnueabi/sysroot
PWD=/mnt/storage/nikita/CAMERA/bsp-initial/buildroot-2021.02.3
HOST_DIR=/mnt/storage/nikita/CAMERA/bsp-initial/output/xm_53h20-s_bsp/host
BR_NO_CCACHE=
BR2_VERSION=2021.02.3
TARGET_DIR=/mnt/storage/nikita/CAMERA/bsp-initial/output/xm_53h20-s_bsp/target
BR_COMPILER_PARANOID_UNSAFE_PATH=enabled
BINARIES_DIR=/mnt/storage/nikita/CAMERA/bsp-initial/output/xm_53h20-s_bsp/images
BR2_CONFIG=/mnt/storage/nikita/CAMERA/bsp-initial/output/xm_53h20-s_bsp/.config
BR2_VERSION_FULL=-ge56fce3-dirty
```
