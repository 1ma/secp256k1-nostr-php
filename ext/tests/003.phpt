--TEST--
test2() Basic test
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php
var_dump(test2());
var_dump(test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
