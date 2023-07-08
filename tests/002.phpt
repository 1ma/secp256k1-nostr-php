--TEST--
test1() Basic test
--EXTENSIONS--
schnorr_nostr
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension schnorr_nostr is loaded and working!
NULL
