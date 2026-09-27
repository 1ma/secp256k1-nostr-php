--TEST--
secp256k1_nostr_derive_pubkey happy path
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php
var_dump(secp256k1_nostr_derive_pubkey('cb6bb4551955d8b5ad3ebc3b3a764601ed4e373f54dd195a8721e7bec24ee42b'));
var_dump(secp256k1_nostr_derive_pubkey('0000000000000000000000000000000000000000000000000000000000000003'));
?>
--EXPECT--
string(64) "1f00befecb50dc441204a6208b80924985b4965563b26845a6e2c12a3b6e37c5"
string(64) "f9308a019258c31049344f85f89d5229b531c845836f99b08601f113bce036f9"
