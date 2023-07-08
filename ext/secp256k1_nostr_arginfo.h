/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: b9971c9cb016b18e92993dcb100fe79743f65616 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_secp256k1_nostr_derive_pubkey, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, privateKey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test1, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test2, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, str, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()


ZEND_FUNCTION(secp256k1_nostr_derive_pubkey);
ZEND_FUNCTION(test1);
ZEND_FUNCTION(test2);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(secp256k1_nostr_derive_pubkey, arginfo_secp256k1_nostr_derive_pubkey)
	ZEND_FE(test1, arginfo_test1)
	ZEND_FE(test2, arginfo_test2)
	ZEND_FE_END
};
