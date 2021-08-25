<p align="center">
 <img src="docs/images/cctv-640x320.png" alt="CCTV">
</p>

<h3 align="center">CCTV</h3>

---

<p align="center">Yet another attempt to make cctv embedded software</p>
<p align="center"><em>Part of OpenHisiIpCam project</em></p>

## :mag: About

Project allows you build custom, mostly open source, maintanable firmware for typical
video surveillance hardware like ip cameras or network video registrators.

**End user documentation, that you advised to read first, can be found on our website
[https://www.openhisiipcam.org/firmware](https://www.openhisiipcam.org/firmware).
Below information is related only for development and some minimal 
relevant skills level expected.**

### Current status

Building on previous experience project is started with planning.
Now it is early stage, where we think, try and plan how things will be
orginized.

* Architecture planning
    * How to describe hardware?
    * ...
* Docker env needed
* Configs
    * Conventions should be determined
    * Typical config flow for some SoC/Family
* Firmware
    * ...

## :closed_book: TOC

* [Quick Start](#quick-start)
* [Internals](#internals)
    * [Repo structure](#repo-structure)
    * [Dive into details](#dive-into-details)
* [Contributing](#contributing)
* [License](#license)

## :rocket: Quick Start

Actually there is no quick start for beginners. But still.

### Prerequisties

It is possible to use this repo directly on your host machine or
via the docker. Recommended usage way is Docker, as it already 
contains all needed enviroiment and prebuilt toolchains 
to build targets.

### Building

Clone repo:
```console
user@host:~$ git clone https://github.com/OpenHisiIpCam/cctv
user@host:~$ cd cctv
```

Check avalible configs:
```console
user@host:~/cctv$ make list-defconfigs
```

Build something:
```console
user@host:~/cctv$ make something_defconfig
user@host:~/cctv$ cd output/something
user@host:~/cctv/something$ make
```

Artifacts can be found in `~/cctv/output/something/images` dir.

## :hammer_and_wrench: Internals

Technically this is Buildroot's external tree with BSPs for target SoCs,
compatible hardware description collection, coordinated configs set,
custom software packages and wrapper enviroiment.

Supported SoCs list and known hardware modules can be found in [boards/README.md](boards/README.md).
For hardware modules maybe better to check generated [catalog](https://www.openhisiipcam.org/firmware/boards).

### :building_construction: Repo structure

As main build system is Buildroot and common way to extend it is so called external tree,
dirs and files organization trys to follow [manual recommendations](https://buildroot.org/downloads/manual/manual.html#customize-dir-structure)
where it is possible.

* boards - BSP, board description collection, config's sources. 
* configs - build configurations for different hardware models, toolchains and dev enviroiment.
* docs - end user documentation (hosted on [https://www.openhisiipcam.org/firmware](https://www.openhisiipcam.org/firmware)).
* package - ???
* scripts - collections of scripts that are invoked during different build stages.
* toolchain - Storage for locally built sdks.
* vendors - 3rd party tools

### Dive into details


Each directory contains it's own detailed README file.


## :???: Contributing
If you have suggestions for how the project could be improved, 
or want to report a bug, open an issue! We'd love all and any contributions.

For more, check out the [Contributing Guide](CONTRIBUTING.md).

## :scroll: License

This project itself is distributed under [the MIT license](LICENSE), 
but there are some modules, that can be compiled into result binaries
that uses prebuilt binary libs that were got from some vendor's SDK
or some public sources, such libs can have rather different licenses 
and usage rules. Please refer to such module`s corresponding README 
and LICENSE files, in order to include them into final binaries.

Dependency projects that are used (can be bundled directly as source code 
or will be downloaded during the build process) are distributed under 
their own licenses, please check their corresponding files.

If you found that some person or company rights are violeted, 
pls contact us (via email or issues on github).
