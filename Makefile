.PHONY: ext ext-with-deps libsodium secp256k1 check coverage install clean

ext:
	cd ext && phpize && ./configure
	$(MAKE) -C ext

ext-with-deps: libsodium secp256k1
	cd ext && phpize && PKG_CONFIG_PATH=$(CURDIR)/vendor/build/lib/pkgconfig ./configure
	$(MAKE) -C ext

libsodium:
	cd vendor/libsodium && ./autogen.sh && ./configure \
		--disable-shared \
		--prefix=$(CURDIR)/vendor/build \
		--with-pic
	$(MAKE) -C vendor/libsodium -j$(shell nproc)
	$(MAKE) -C vendor/libsodium install

secp256k1:
	cd vendor/secp256k1 && ./autogen.sh && ./configure \
		--disable-benchmark \
		--disable-ctime-tests \
		--disable-examples \
		--disable-exhaustive-tests \
		--disable-shared \
		--disable-tests \
		--prefix=$(CURDIR)/vendor/build \
		--with-pic
	$(MAKE) -C vendor/secp256k1 -j$(shell nproc)
	$(MAKE) -C vendor/secp256k1 install

check:
	$(MAKE) -C ext test \
		TESTS="-q -m --show-diff --show-mem" \
		VALGRIND_OPTS="--gen-suppressions=all --suppressions=$(CURDIR)/ext/valgrind-php.supp"

coverage: libsodium secp256k1
	cd ext && phpize && CFLAGS="--coverage -O0 -g" LDFLAGS="--coverage" PKG_CONFIG_PATH=$(CURDIR)/vendor/build/lib/pkgconfig ./configure
	$(MAKE) -C ext
	$(MAKE) -C ext test TESTS="-q --show-diff"
	lcov --capture --directory ext/.libs --output-file ext/coverage.info --include '$(CURDIR)/ext/*'
	genhtml ext/coverage.info --output-directory ext/coverage-html
	@echo "Coverage report: ext/coverage-html/index.html"

install:
	$(MAKE) -C ext install

clean:
	$(MAKE) -C ext clean
	$(MAKE) -C vendor/libsodium clean
	$(MAKE) -C vendor/secp256k1 clean
	rm -rf build ext/coverage-html ext/coverage.info
