MODULES=$(wildcard *.ko)
OBJECTS=$(patsubst %.ko,%.o,$(wildcard *.ko))

all: $(OBJECTS)

%.o: %.ko
	ld -r -b binary -o $@ $<

clean:
	rm -f $(OBJECTS)
