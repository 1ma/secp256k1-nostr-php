/* secp256k1_nostr extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_secp256k1_nostr.h"
#include "secp256k1_nostr_arginfo.h"

#include <assert.h>
#include <secp256k1.h>
#include <secp256k1_extrakeys.h>
#include <secp256k1_schnorrsig.h>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

PHP_FUNCTION(secp256k1_nostr_derive_pubkey)
{
    secp256k1_context* ctx;
    secp256k1_keypair keypair;
    secp256k1_xonly_pubkey xonly_pubkey;

    char *pubkey;
    char *seckey;
    size_t seckey_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(seckey, seckey_len)
    ZEND_PARSE_PARAMETERS_END();

    if (seckey_len != 64) {
        // TODO throw error
    }

    // TODO run seckey through hex2bin

    ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    assert(secp256k1_keypair_create(ctx, &keypair, seckey));
    assert(secp256k1_keypair_xonly_pub(ctx, &xonly_pubkey, NULL, &keypair));
    assert(secp256k1_xonly_pubkey_serialize(ctx, pubkey, &xonly_pubkey));

    // TODO run pubkey through bin2hex
    // TODO return hexed pubkey
}

/* {{{ void test1() */
PHP_FUNCTION(test1)
{
    ZEND_PARSE_PARAMETERS_NONE();

    unsigned char pubkey[32] = {
        0x1f, 0x00, 0xbe, 0xfe, 0xcb, 0x50, 0xdc, 0x44, 0x12, 0x04, 0xa6, 0x20, 0x8b, 0x80, 0x92, 0x49,
        0x85, 0xb4, 0x96, 0x55, 0x63, 0xb2, 0x68, 0x45, 0xa6, 0xe2, 0xc1, 0x2a, 0x3b, 0x6e, 0x37, 0xc5
    };

    unsigned char message[32] = {
        0x89, 0xea, 0xb2, 0x65, 0xa7, 0xe5, 0x20, 0xb0, 0x70, 0xee, 0x2e, 0x9a, 0x56, 0xb1, 0xae, 0x53,
        0x2f, 0xac, 0x0b, 0xd9, 0x11, 0xd0, 0x90, 0x86, 0x79, 0x43, 0xb6, 0x4f, 0x32, 0xb6, 0x39, 0x6e
    };

    unsigned char signature[64] = {
        0xbb, 0xfe, 0xc4, 0xd5, 0xf7, 0xc7, 0xa1, 0xa3, 0xd9, 0x1d, 0x69, 0xe5, 0x02, 0x0b, 0x71, 0xfc,
        0xf7, 0xca, 0x42, 0x7c, 0xf7, 0x06, 0x0e, 0xfa, 0xc8, 0x4f, 0xbb, 0x2c, 0x38, 0xf1, 0x02, 0x42,
        0xc6, 0xaf, 0x33, 0x4c, 0x35, 0xee, 0x0f, 0xd5, 0x2a, 0xc3, 0x06, 0x68, 0x38, 0x21, 0xdc, 0xad,
        0x95, 0x82, 0xc3, 0x98, 0xbb, 0xe7, 0xf9, 0x6b, 0x2f, 0xd5, 0xe4, 0x92, 0x67, 0x65, 0x4d, 0x9f
    };

    secp256k1_xonly_pubkey xonly_pubkey;

    secp256k1_selftest();
    assert(secp256k1_xonly_pubkey_parse(secp256k1_context_static, &xonly_pubkey, pubkey));

    assert(secp256k1_schnorrsig_verify(secp256k1_context_static, signature, message, sizeof(message), &xonly_pubkey));

    php_printf("The extension %s is loaded and working!\r\n", "secp256k1_nostr");
}
/* }}} */

/* {{{ string test2( [ string $var ] ) */
PHP_FUNCTION(test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION */
PHP_MINIT_FUNCTION(secp256k1_nostr)
{
#if defined(ZTS) && defined(COMPILE_DL_SECP256K1_NOSTR)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(secp256k1_nostr)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "secp256k1_nostr support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ secp256k1_nostr_module_entry */
zend_module_entry secp256k1_nostr_module_entry = {
	STANDARD_MODULE_HEADER,
	"secp256k1_nostr",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	PHP_MINIT(secp256k1_nostr),			/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	NULL,			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(secp256k1_nostr),			/* PHP_MINFO - Module info */
	PHP_SECP256K1_NOSTR_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SECP256K1_NOSTR
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(secp256k1_nostr)
#endif
