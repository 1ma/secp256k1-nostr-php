--TEST--
Check if secp256k1_nostr is loaded
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php
echo 'The extension "secp256k1_nostr" is available';
?>
--EXPECT--
The extension "secp256k1_nostr" is available
