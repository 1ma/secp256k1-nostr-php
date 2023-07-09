--TEST--
secp256k1_nostr_sign invalid usages
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php

try {
    secp256k1_nostr_sign(
        hex2bin('deadbeef'),
        hex2bin('89eab265a7e520b070ee2e9a56b1ae532fac0bd911d090867943b64f32b6396e')
    );
} catch (\InvalidArgumentException $e) {
    var_dump($e->getMessage());
}

try {
    secp256k1_nostr_sign(
        hex2bin('0000000000000000000000000000000000000000000000000000000000000000'),
        hex2bin('89eab265a7e520b070ee2e9a56b1ae532fac0bd911d090867943b64f32b6396e')
    );
} catch (\InvalidArgumentException $e) {
    var_dump($e->getMessage());
}

try {
    secp256k1_nostr_sign(
        hex2bin('cb6bb4551955d8b5ad3ebc3b3a764601ed4e373f54dd195a8721e7bec24ee42b'),
        hex2bin('deadbeef')
    );
} catch (\InvalidArgumentException $e) {
    var_dump($e->getMessage());
}

?>
--EXPECT--
string(56) "secp256k1_nostr_sign(): Parameter 1 is not 32 bytes long"
string(62) "secp256k1_nostr_sign(): Parameter 1 is not a valid private key"
string(56) "secp256k1_nostr_sign(): Parameter 2 is not 32 bytes long"
