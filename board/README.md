# Boards and Board Support Packages

**B**oard **S**upport **P**ackage here is

## List

|Name       |Vendor   |SoCs|
|-----------|---------|----|
|gk710x     |Goke     |    |
|hi3516av100|HiSilicon|    |
|hi3516av200|HiSilicon|    |
|hi3516cv100|HiSilicon|    |
|hi3516cv200|HiSilicon|    |
|hi3516cv300|HiSilicon|    |
|hi3516cv500|HiSilicon|    |
|hi3516ev200|HiSilicon|    |
|hi3519av100|HiSilicon|    |
|hi3536dv100|HiSilicon|    |
|infinity6b0|SigmaStar|    |
|nt9852x    |Novatek  |    |
|nt9856x    |Novatek  |    |
|rv11xx     |RockChip |    |
|xm530      |XiongMai |    |

## Notes

### Typical patches for old kernel (< 4.9)

**TODO**

* BR`s patches
* gccX
* asm`s register const -> register

### Uboot

* https://github.com/u-boot/u-boot/commit/de39dc71625d1a66cc611d1a85bf53545cba60a3#diff-1e9338600fcf62754807d32f9e27ce7b2c2794d5c470ec3780c644a9793de320

## References

**TODO**

## Board descruption structure
Some files are common, some are platform specific.

```
./board/
├── back.jpg
├── board.yml
├── bsp.br.config
├── front.jpg
├── pinouts1.jpg
├── pinouts2.jpg
└── reg.bin

???:
	dir images
	dir docs
	dir dumps
```

## BSPs

```
.
├── fullhan
│   ├── fh8856
├── goke
│   ├── gk710x
│   ├── gk7205v200
├── grainmedia
│   ├── gm8136
│   ├── gm8139
├── hisilicon
│   ├── hi3516av100
│   ├── hi3516av200
│   ├── hi3516cv100
│   ├── hi3516cv200
│   ├── hi3516cv300
│   ├── hi3516cv500
│   ├── hi3516ev200
│   ├── hi3519av100
│   ├── hi3536dv100
├── novatek
│   ├── nt9852x
│   └── nt9856x
├── sigmastar
│   ├── infinity6b0
│   ├── infinity6e
└── xiongmai
    └── xm530
```
