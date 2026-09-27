--TEST--
secp256k1_nostr phpinfo output
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php
ob_start();
phpinfo(INFO_MODULES);
$info = ob_get_clean();

var_dump(str_contains($info, 'secp256k1_nostr support'));
?>
--EXPECT--
bool(true)
