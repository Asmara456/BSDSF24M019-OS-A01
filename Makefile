# Top-level Makefile (recursive): delegates the work to src/
SUBDIRS = src
PREFIX  = /usr/local
BINDIR  = $(PREFIX)/bin
MANDIR  = $(PREFIX)/share/man/man3

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

run: all
	./bin/client_static

install: all
	install -m 755 bin/client_static $(BINDIR)/client
	install -m 755 bin/client_dynamic $(BINDIR)/client_dynamic
	mkdir -p $(MANDIR)
	install -m 644 man/man3/*.3 $(MANDIR)
	mandb

uninstall:
	rm -f $(BINDIR)/client $(BINDIR)/client_dynamic
	rm -f $(MANDIR)/mystrlen.3 $(MANDIR)/mystrcpy.3 $(MANDIR)/mystrncpy.3 $(MANDIR)/mystrcat.3 $(MANDIR)/wordCount.3 $(MANDIR)/mygrep.3

clean:
	$(MAKE) -C src clean

.PHONY: all run install uninstall clean $(SUBDIRS)
