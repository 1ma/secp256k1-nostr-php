/* schnorr_nostr extension for PHP */

#ifndef PHP_SCHNORR_NOSTR_H
# define PHP_SCHNORR_NOSTR_H

extern zend_module_entry schnorr_nostr_module_entry;
# define phpext_schnorr_nostr_ptr &schnorr_nostr_module_entry

# define PHP_SCHNORR_NOSTR_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_SCHNORR_NOSTR)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_SCHNORR_NOSTR_H */
