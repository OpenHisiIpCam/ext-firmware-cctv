# Coding guidelines

## Naming

**TODO**

## Code styling

We use clang-format, don't format code by your own. Just do:
```
make style
```

## Documenting

**TODO**

```
make ../docs/doxygen
```

## Treating was value set or not

* Strings `char *` null is not set
* Unsigned integer `int` -1 is not set
* Signed integer `int` MIN_INT is not set ???

## Different platforms support

**TODO**

## Reference

* [C coding style](https://codingart.readthedocs.io/en/latest/c)
* [GNU coding standards](https://www.gnu.org/prep/standards/html_node/Writing-C.html) and [this](https://www.gnu.org/prep/standards/standards.html)
* [C header file guidelines](http://www.umich.edu/~eecs381/handouts/CHeaderFileGuidelines.pdf)
