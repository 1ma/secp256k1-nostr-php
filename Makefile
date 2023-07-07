.PHONY: clean secp256k1

all: derive_pubkey gen_keypair signature verification

derive_pubkey: samples/derive_pubkey.c
	gcc \
	-I vendor/bitcoin-core/secp256k1/include \
	-I vendor/bitcoin-core/secp256k1/examples \
	-o derive_pubkey.x \
	samples/derive_pubkey.c \
	vendor/bitcoin-core/secp256k1/.libs/libsecp256k1.a

gen_keypair: samples/gen_keypair.c
	gcc \
	-I vendor/bitcoin-core/secp256k1/include \
	-I vendor/bitcoin-core/secp256k1/examples \
	-o gen_keypair.x \
	samples/gen_keypair.c \
	vendor/bitcoin-core/secp256k1/.libs/libsecp256k1.a

signature: samples/signature.c
	gcc \
	-I vendor/bitcoin-core/secp256k1/include \
	-I vendor/bitcoin-core/secp256k1/examples \
	-o signature.x \
	samples/signature.c \
	vendor/bitcoin-core/secp256k1/.libs/libsecp256k1.a

verification: samples/verification.c
	gcc \
	-I vendor/bitcoin-core/secp256k1/include \
	-I vendor/bitcoin-core/secp256k1/examples \
	-o verification.x \
	samples/verification.c \
	vendor/bitcoin-core/secp256k1/.libs/libsecp256k1.a

clean:
	rm -f *.x

secp256k1:
	composer install
	cd vendor/bitcoin-core/secp256k1 && \
	./autogen.sh && \
	./configure
	make -C vendor/bitcoin-core/secp256k1 -j$(shell nproc)
