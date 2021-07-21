<p align="center">
 <img src="docs/images/cctv-640x320.png" alt="CCTV">
</p>

<h3 align="center">CCTV</h3>

---

<p align="center">Yet another attempt to make cctv embedded software</p>
<p align="center"><em>Part of OpenHisiIpCam project</em></p>

## :mag: About

## :closed_book: TOC

* [Quick Start](#quick-start)
* [Architecture overview](#architecture-overview)
* [Repo structure](#repo-structure)
* [Contributing](#contributing)
* [License](#license)

## :rocket: Quick Start

**At the moment this repo maybe interesting only for developers, 
as it can't produce any interesting result for end user.**

### Clone repo
```console
$ git clone --recursive https://github.com/OpenHisiIpCam/cctv
```

### Toolchain
```console
$ cd toolchain; make all
```

Common operations avaliable via root Makefile.

### Docs

Actual `/docs` are hosted on https://openhisiipcam.org/

```
$ make output/docs
```

**TODO**

## :hammer_and_wrench: Architecture overview

Main build system is Buildroot

## :building_construction: Repo structure

```
TODO
```

## Contributing
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
