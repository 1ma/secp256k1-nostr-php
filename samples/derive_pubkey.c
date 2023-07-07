#include <assert.h>
#include <string.h>

#include <secp256k1.h>
#include <secp256k1_extrakeys.h>

#include "examples_util.h"

int main(void) {
    unsigned char pubkey[32];
    unsigned char seckey[32] = {
        0xcb, 0x6b, 0xb4, 0x55, 0x19, 0x55, 0xd8, 0xb5, 0xad, 0x3e, 0xbc, 0x3b, 0x3a, 0x76, 0x46, 0x01,
        0xed, 0x4e, 0x37, 0x3f, 0x54, 0xdd, 0x19, 0x5a, 0x87, 0x21, 0xe7, 0xbe, 0xc2, 0x4e, 0xe4, 0x2b
    };

    secp256k1_context* ctx;
    secp256k1_keypair keypair;
    secp256k1_xonly_pubkey xonly_pubkey;

    ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    assert(secp256k1_keypair_create(ctx, &keypair, seckey));
    assert(secp256k1_keypair_xonly_pub(ctx, &xonly_pubkey, NULL, &keypair));
    assert(secp256k1_xonly_pubkey_serialize(ctx, pubkey, &xonly_pubkey));

    // Sanity check. Should print:
    // 0xcb6bb4551955d8b5ad3ebc3b3a764601ed4e373f54dd195a8721e7bec24ee42b
    // 0x1f00befecb50dc441204a6208b80924985b4965563b26845a6e2c12a3b6e37c5
    print_hex(seckey, sizeof(seckey));
    print_hex(pubkey, sizeof(pubkey));

    return 0;
}
