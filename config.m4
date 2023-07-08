dnl config.m4 for extension schnorr_nostr

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([schnorr_nostr],
dnl   [for schnorr_nostr support],
dnl   [AS_HELP_STRING([--with-schnorr_nostr],
dnl     [Include schnorr_nostr support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([schnorr_nostr],
  [whether to enable schnorr_nostr support],
  [AS_HELP_STRING([--enable-schnorr_nostr],
    [Enable schnorr_nostr support])],
  [no])

if test "$PHP_SCHNORR_NOSTR" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, SCHNORR_NOSTR_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-schnorr_nostr -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/schnorr_nostr.h"  # you most likely want to change this
  dnl if test -r $PHP_SCHNORR_NOSTR/$SEARCH_FOR; then # path given as parameter
  dnl   SCHNORR_NOSTR_DIR=$PHP_SCHNORR_NOSTR
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for schnorr_nostr files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SCHNORR_NOSTR_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SCHNORR_NOSTR_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the schnorr_nostr distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-schnorr_nostr -> add include path
  dnl PHP_ADD_INCLUDE($SCHNORR_NOSTR_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-schnorr_nostr -> check for lib and symbol presence
  dnl LIBNAME=SCHNORR_NOSTR # you may want to change this
  dnl LIBSYMBOL=SCHNORR_NOSTR # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_SCHNORR_NOSTR_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your schnorr_nostr library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SCHNORR_NOSTR_DIR/$PHP_LIBDIR, SCHNORR_NOSTR_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SCHNORR_NOSTR_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your schnorr_nostr library.])
  dnl ],[
  dnl   -L$SCHNORR_NOSTR_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SCHNORR_NOSTR_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_SCHNORR_NOSTR, 1, [ Have schnorr_nostr support ])

  PHP_ADD_INCLUDE(vendor/bitcoin-core/secp256k1/include)
  PHP_ADD_LIBRARY_WITH_PATH(secp256k1, vendor/bitcoin-core/secp256k1/.libs/libsecp256k1.a, SECP256K1_SHARED_LIBADD)

  PHP_NEW_EXTENSION(schnorr_nostr, schnorr_nostr.c, $ext_shared)
fi
