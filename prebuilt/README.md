# Prebuilt host packages for Buildroot

This part of infrastructure build common host packages 
(check `packages` file), that used by Buildroot during 
any build process and saves needed files in dir named as 
BR's version.

Later if some build is invoked root Makefile will copy 
prebuilts and their build will not consume any time
during build process.

To build this invoke `make` from this dir 
or `make prebuilt` from repo root.

**Status: experimental.**

**This is only useful if you plan to build/rebuild targets 
many times.**

## Notes

It is not possible to prebuilt any packages that relay on 
target architecture.

All needed host packages should be listed on `packages` file.
Means that even all deps (that will be built by BR automatically)
for some package should be listed. Otherwise deps will not be copied
to prebuilt archive.

Prebuilts relay on host system, so they should not be transfered 
from machine to machine.

## TODO

Now rellocation done in two step:
* replace old path to marker during packing
* replace marker with new path durin apply
This can be done in one step during apply,
if we will save old path in some file.

Current implementation is slow, there should be
some way to speed up the process.
