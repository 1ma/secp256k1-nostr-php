--TEST--
secp256k1_nostr_derive_pubkey invalid usages
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php
try {
    secp256k1_nostr_derive_pubkey(hex2bin('deadbeef'));
} catch (\InvalidArgumentException $e) {
    var_dump($e->getMessage());
}

try {
    secp256k1_nostr_derive_pubkey(hex2bin('0000000000000000000000000000000000000000000000000000000000000000'));
} catch (\InvalidArgumentException $e) {
    var_dump($e->getMessage());
}
?>
--EXPECT--
string(65) "secp256k1_nostr_derive_pubkey(): Parameter 1 is not 32 bytes long"
string(71) "secp256k1_nostr_derive_pubkey(): Parameter 1 is not a valid private key"
