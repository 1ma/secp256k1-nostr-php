/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 4346430733870d2ceb84486b54608f383921af44 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_secp256k1_nostr_derive_pubkey, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, privateKey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_secp256k1_nostr_sign, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, privateKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, hash, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_secp256k1_nostr_verify, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, publicKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, hash, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, signature, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(secp256k1_nostr_derive_pubkey);
ZEND_FUNCTION(secp256k1_nostr_sign);
ZEND_FUNCTION(secp256k1_nostr_verify);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(secp256k1_nostr_derive_pubkey, arginfo_secp256k1_nostr_derive_pubkey)
	ZEND_FE(secp256k1_nostr_sign, arginfo_secp256k1_nostr_sign)
	ZEND_FE(secp256k1_nostr_verify, arginfo_secp256k1_nostr_verify)
	ZEND_FE_END
};
