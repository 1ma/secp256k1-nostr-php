--TEST--
Check if secp256k1_nostr is loaded
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php
try {
    secp256k1_nostr_derive_pubkey(hex2bin('deadbeef'));
} catch (\InvalidArgumentException $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    secp256k1_nostr_derive_pubkey(hex2bin('0000000000000000000000000000000000000000000000000000000000000000'));
} catch (\InvalidArgumentException $e) {
    echo $e->getMessage() . PHP_EOL;
}
?>
--EXPECT--
secp256k1_nostr_derive_pubkey(): Parameter 1 is not 32 bytes long
secp256k1_nostr_derive_pubkey(): Parameter 1 is not a valid private key
