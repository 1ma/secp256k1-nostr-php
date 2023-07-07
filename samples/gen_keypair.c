#include <assert.h>
#include <string.h>

#include <secp256k1.h>
#include <secp256k1_extrakeys.h>

#include "examples_util.h"

int main(void) {
    unsigned char pubkey[32];
    unsigned char seckey[32];

    assert(fill_random(seckey, sizeof(seckey)));

    secp256k1_context* ctx;
    secp256k1_keypair keypair;
    secp256k1_xonly_pubkey xonly_pubkey;

    ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    assert(secp256k1_keypair_create(ctx, &keypair, seckey));
    assert(secp256k1_keypair_xonly_pub(ctx, &xonly_pubkey, NULL, &keypair));
    assert(secp256k1_xonly_pubkey_serialize(ctx, pubkey, &xonly_pubkey));

    print_hex(seckey, sizeof(seckey));
    print_hex(pubkey, sizeof(pubkey));

    return 0;
}
