#!/bin/sh 

echo "aclocal.."
aclocal --force         || exit 1
echo "autoheader.."     || exit 1
autoheader --force      || exit 1
echo "automake.."       || exit 1
automake --force --add-missing  || exit 1
echo "autoconf.."
autoconf --force        || exit 1
