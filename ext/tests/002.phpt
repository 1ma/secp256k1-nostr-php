--TEST--
test1() Basic test
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php
echo bin2hex(secp256k1_nostr_derive_pubkey(hex2bin('35349f19bc4d11c427d1bf4eaa40e5755240e147a624578d9db43390fd63e8c3')));
?>
--EXPECT--
cef7d0f7ce50d1d5d5001b272c7d81fcd4cdb1cc983b12b0703804dfcc839a09
