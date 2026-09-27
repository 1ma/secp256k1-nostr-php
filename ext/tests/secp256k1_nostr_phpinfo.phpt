--TEST--
secp256k1_nostr phpinfo output
--EXTENSIONS--
secp256k1_nostr
--FILE--
<?php
ob_start();
phpinfo(INFO_MODULES);
$info = ob_get_clean();

var_dump(strpos($info, 'secp256k1_nostr support') !== false);
?>
--EXPECT--
bool(true)
