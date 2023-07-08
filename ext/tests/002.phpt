--TEST--
test1() Basic test
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension secp256k1_nostr is loaded and working!
NULL
