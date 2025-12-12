.PHONY: ext libsodium secp256k1 check check-valgrind install clean

ext:
	cd ext && \
	phpize && \
	./configure
	$(MAKE) -C ext

ext-with-deps: libsodium secp256k1
	cd ext && \
	phpize && \
	./configure PKG_CONFIG_PATH=$(shell pwd)/build/lib/pkgconfig
	$(MAKE) -C ext

libsodium:
	cd vendor/libsodium && \
	./autogen.sh && \
	./configure \
		--prefix=$(shell pwd)/build \
		--with-pic
	$(MAKE) -C vendor/libsodium -j$(shell nproc)
	$(MAKE) -C vendor/libsodium install

secp256k1:
	cd vendor/secp256k1 && \
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
	$(MAKE) -C vendor/secp256k1 -j$(shell nproc)
	$(MAKE) -C vendor/secp256k1 install

check:
	$(MAKE) -C ext test TESTS="-q --show-diff"

check-valgrind:
	$(MAKE) -C ext test TESTS="-q -m --show-diff --show-mem" \
		VALGRIND_OPTS="--gen-suppressions=all --suppressions=$(CURDIR)/ext/valgrind-php-jit.supp"

install:
	$(MAKE) -C ext install

clean:
	$(MAKE) -C ext clean
	$(MAKE) -C vendor/libsodium clean
	$(MAKE) -C vendor/secp256k1 clean
	rm -rf build
