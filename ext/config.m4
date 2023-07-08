PHP_ARG_WITH([secp256k1_nostr],
  [for secp256k1_nostr support],
  [AS_HELP_STRING([--with-secp256k1_nostr],
    [Include secp256k1_nostr support])])

if test "$PHP_SECP256K1_NOSTR" != "no"; then
  PKG_CHECK_MODULES([LIBSECP256K1], [libsecp256k1 = 0.3.2])
  PHP_EVAL_INCLINE($LIBSECP256K1_CFLAGS)
  PHP_EVAL_LIBLINE($LIBSECP256K1_LIBS, SECP256K1_NOSTR_SHARED_LIBADD)

  PHP_SUBST(SECP256K1_NOSTR_SHARED_LIBADD)

  AC_DEFINE(HAVE_SECP256K1_NOSTR, 1, [ Have secp256k1_nostr support ])

  PHP_NEW_EXTENSION(secp256k1_nostr, hex.c secp256k1_nostr.c, $ext_shared)
fi
