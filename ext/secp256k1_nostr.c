/* secp256k1_nostr extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/spl/spl_exceptions.h"
#include "ext/standard/info.h"
#include "ext/standard/php_random.h"
#include "zend_exceptions.h"

#include "secp256k1_nostr_arginfo.h"
#include "php_secp256k1_nostr.h"

#include "secp256k1.h"
#include "secp256k1_extrakeys.h"
#include "secp256k1_schnorrsig.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

PHP_FUNCTION(secp256k1_nostr_derive_pubkey)
{
    zend_string* in_seckey;
    zend_string* out_pubkey;

    secp256k1_context* ctx;
    secp256k1_keypair keypair;
    secp256k1_xonly_pubkey xonly_pubkey;
    unsigned char pubkey[32];

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(in_seckey)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(in_seckey) != 32) {
        zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "secp256k1_nostr_derive_pubkey(): Parameter 1 is not 32 bytes long");
        return;
    }

    ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    if(!secp256k1_keypair_create(ctx, &keypair, (unsigned char *)ZSTR_VAL(in_seckey))) {
        zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "secp256k1_nostr_derive_pubkey(): Parameter 1 is not a valid private key");
        return;
    }

    secp256k1_keypair_xonly_pub(ctx, &xonly_pubkey, NULL, &keypair);
    secp256k1_xonly_pubkey_serialize(ctx, pubkey, &xonly_pubkey);
    secp256k1_context_destroy(ctx);

    out_pubkey = zend_string_init(pubkey, sizeof(pubkey), 0);

    RETURN_STR(out_pubkey);
}

PHP_FUNCTION(secp256k1_nostr_sign)
{
    zend_string* in_seckey;
    zend_string* in_message;
    zend_string* out_signature;

    secp256k1_context* ctx;
    secp256k1_keypair keypair;
    unsigned char auxiliary_rand[32];
    unsigned char signature[64];

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(in_seckey)
        Z_PARAM_STR(in_message)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(in_seckey) != 32) {
        zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "secp256k1_nostr_sign(): Parameter 1 is not 32 bytes long");
        return;
    }

    if (ZSTR_LEN(in_message) != 32) {
        zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "secp256k1_nostr_sign(): Parameter 2 is not 32 bytes long");
        return;
    }

    ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    if(!secp256k1_keypair_create(ctx, &keypair, (unsigned char *)ZSTR_VAL(in_seckey))) {
        zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "secp256k1_nostr_derive_pubkey(): Parameter 1 is not a valid private key");
        return;
    }
    
    if(php_random_bytes_throw(auxiliary_rand, sizeof(auxiliary_rand)) == FAILURE) {
        zend_throw_exception_ex(spl_ce_RuntimeException, 0, "secp256k1_nostr_derive_pubkey(): Error fetching entropy");
        return;
    }

    secp256k1_schnorrsig_sign32(ctx, signature, (unsigned char *)ZSTR_VAL(in_message), &keypair, auxiliary_rand);

    out_signature = zend_string_init(signature, sizeof(signature), 0);

    RETURN_STR(out_signature);
}

PHP_FUNCTION(secp256k1_nostr_verify)
{
    zend_string *out;
    out = zend_string_init("hola :)", 7, 0);

    RETURN_STR(out);
}

/* {{{ PHP_MINIT_FUNCTION */
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
