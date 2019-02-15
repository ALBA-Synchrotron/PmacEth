libpcommx.so.4.0.0: pcommx.o
	gcc -gstabs+ -shared -Wl,-soname,libpcommx.so.4 -o libpcommx.so.4.0.0 pcommx.o -lc
	ln -s libpcommx.so.4.0.0 libpcommx.so.4
	ln -s libpcommx.so.4 libpcommx.so

pcommx.o: pcommx.c pcommx.h
	gcc -g -fPIC -c pcommx.c

all: libpcommx.so.4.0.0

clean:
	rm libpcommx.so.4.0.0 libpcommx.so.4 libpcommx.so
	rm pcommx.o
