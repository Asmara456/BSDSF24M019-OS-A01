# Top-level Makefile (recursive): delegates the work to src/
SUBDIRS = src

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

run: all
	./bin/client_static

clean:
	$(MAKE) -C src clean

.PHONY: all run clean $(SUBDIRS)
