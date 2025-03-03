.PHONY: ext libsodium secp256k1 check check-valgrind install clean

ext:
	cd ext && \
	phpize && \
	./configure PKG_CONFIG_PATH=$(shell pwd)/build/lib/pkgconfig
	make -C ext

libsodium:
	cd libsodium && \
	./autogen.sh && \
	./configure \
		--prefix=$(shell pwd)/build \
		--with-pic
	make -C libsodium -j$(shell nproc)
	make -C libsodium install

secp256k1:
	cd secp256k1 && \
	./autogen.sh && \
	./configure \
		--disable-benchmark \
		--disable-ctime-tests \
		--disable-examples \
		--disable-exhaustive-tests \
		--disable-shared \
		--disable-tests \
		--prefix=$(shell pwd)/build \
		--with-pic
	make -C secp256k1 -j$(shell nproc)
	make -C secp256k1 install

check:
	make -C ext test TESTS="-q --show-diff"

check-valgrind:
	make -C ext test TESTS="-q -m --show-diff --show-mem"

install:
	make -C ext install

clean:
	make -C ext clean
	make -C libsodium clean
	make -C secp256k1 clean
	rm -rf build
