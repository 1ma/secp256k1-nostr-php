--TEST--
secp256k1_nostr_verify invalid usages
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php

try {
    secp256k1_nostr_verify(
        hex2bin('deadbeef'),
        hex2bin('89eab265a7e520b070ee2e9a56b1ae532fac0bd911d090867943b64f32b6396e'),
        hex2bin('bbfec4d5f7c7a1a3d91d69e5020b71fcf7ca427cf7060efac84fbb2c38f10242c6af334c35ee0fd52ac306683821dcad9582c398bbe7f96b2fd5e49267654d9f'),
    );
} catch (\InvalidArgumentException $e) {
    var_dump($e->getMessage());
}

try {
    secp256k1_nostr_verify(
        hex2bin('0000000000000000000000000000000000000000000000000000000000000000'),
        hex2bin('89eab265a7e520b070ee2e9a56b1ae532fac0bd911d090867943b64f32b6396e'),
        hex2bin('bbfec4d5f7c7a1a3d91d69e5020b71fcf7ca427cf7060efac84fbb2c38f10242c6af334c35ee0fd52ac306683821dcad9582c398bbe7f96b2fd5e49267654d9f'),
    );
} catch (\InvalidArgumentException $e) {
    var_dump($e->getMessage());
}

try {
    secp256k1_nostr_verify(
        hex2bin('1f00befecb50dc441204a6208b80924985b4965563b26845a6e2c12a3b6e37c5'),
        hex2bin('deadbeef'),
        hex2bin('bbfec4d5f7c7a1a3d91d69e5020b71fcf7ca427cf7060efac84fbb2c38f10242c6af334c35ee0fd52ac306683821dcad9582c398bbe7f96b2fd5e49267654d9f'),
    );
} catch (\InvalidArgumentException $e) {
    var_dump($e->getMessage());
}

try {
    secp256k1_nostr_verify(
        hex2bin('1f00befecb50dc441204a6208b80924985b4965563b26845a6e2c12a3b6e37c5'),
        hex2bin('89eab265a7e520b070ee2e9a56b1ae532fac0bd911d090867943b64f32b6396e'),
        hex2bin('deadbeef'),
    );
} catch (\InvalidArgumentException $e) {
    var_dump($e->getMessage());
}

?>
--EXPECT--
string(58) "secp256k1_nostr_verify(): Parameter 1 is not 32 bytes long"
string(63) "secp256k1_nostr_verify(): Parameter 1 is not a valid public key"
string(58) "secp256k1_nostr_verify(): Parameter 2 is not 32 bytes long"
string(58) "secp256k1_nostr_verify(): Parameter 3 is not 64 bytes long"
