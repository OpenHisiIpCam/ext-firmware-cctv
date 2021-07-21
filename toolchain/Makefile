TOOLCHAIN_MD5SUMS = $(patsubst %.tar.gz,%.tar.gz.md5sum,$(wildcard *.tar.gz))

.PHONY: md5sums
md5sums: clean $(TOOLCHAIN_MD5SUMS)

%.tar.gz.md5sum: %.tar.gz
	md5sum $< >> md5sums

.PHONY: clean
clean:
	rm -f md5sums
