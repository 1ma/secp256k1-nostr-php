.PHONY: clean secp256k1

all: derive_pubkey gen_keypair signature verification

derive_pubkey: derive_pubkey.c
	gcc \
	-I ../secp256k1/include \
	-I ../secp256k1/examples \
	-o derive_pubkey.x \
	derive_pubkey.c \
	../secp256k1/.libs/libsecp256k1.a

gen_keypair: gen_keypair.c
	gcc \
	-I ../secp256k1/include \
	-I ../secp256k1/examples \
	-o gen_keypair.x \
	gen_keypair.c \
	../secp256k1/.libs/libsecp256k1.a

signature: signature.c
	gcc \
	-I ../secp256k1/include \
	-I ../secp256k1/examples \
	-o signature.x \
	signature.c \
	../secp256k1/.libs/libsecp256k1.a

verification: verification.c
	gcc \
	-I ../secp256k1/include \
	-I ../secp256k1/examples \
	-o verification.x \
	verification.c \
	../secp256k1/.libs/libsecp256k1.a

clean:
	rm -f *.x

secp256k1:
	cd ../secp256k1 && \
	./autogen.sh && \
	./configure --with-pic
	make -C ../secp256k1 -j$(shell nproc)
