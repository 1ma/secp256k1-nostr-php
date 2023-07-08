.PHONY: ext secp256k1 samples check clean

ext:
	cd ext && \
	phpize && \
	./configure PKG_CONFIG_PATH=$(shell pwd)/build/lib/pkgconfig
	make -C ext

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

samples:
	mkdir -p build/bin
	gcc -g -I secp256k1/include -I secp256k1/examples -o build/bin/derive_pubkey samples/derive_pubkey.c build/lib/libsecp256k1.a
	gcc -g -I secp256k1/include -I secp256k1/examples -o build/bin/gen_keypair   samples/gen_keypair.c   build/lib/libsecp256k1.a
	gcc -g -I secp256k1/include -I secp256k1/examples -o build/bin/signature     samples/signature.c     build/lib/libsecp256k1.a
	gcc -g -I secp256k1/include                       -o build/bin/verification  samples/verification.c  build/lib/libsecp256k1.a

check:
	make -C ext test TESTS="-q -m --show-diff --show-mem"

clean:
	make -C ext clean
	make -C secp256k1 clean
	rm -rf build
