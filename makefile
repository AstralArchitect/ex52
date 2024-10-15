all:
	meson compile -C builddir
setup:
	meson setup builddir
run: all
	./builddir/main