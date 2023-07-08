--TEST--
Check if schnorr_nostr is loaded
--EXTENSIONS--
schnorr_nostr
--FILE--
<?php
echo 'The extension "schnorr_nostr" is available';
?>
--EXPECT--
The extension "schnorr_nostr" is available
