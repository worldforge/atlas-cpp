#! /bin/sh

echo aclocal...
(aclocal --version) < /dev/null > /dev/null 2>&1 || {
    echo aclocal not found
    exit 1
}

aclocal

echo autoheader...
(autoheader --version) < /dev/null > /dev/null 2>&1 || {
    echo autoheader not found
    exit 1
}    

autoheader

echo libtoolize...
if which libtoolize > /dev/null; then
  echo "Found libtoolize"
  LIBTOOLIZE='libtoolize'
elif which glibtoolize > /dev/null; then
  echo "Found glibtoolize"
  LIBTOOLIZE='glibtoolize'
else
  echo "Failed to find libtoolize or glibtoolize, please ensure it is installed and accessible via your PATH env variable"
  exit 1
fi;

$LIBTOOLIZE  --automake --copy --force

echo automake...
(automake --version) < /dev/null > /dev/null 2>&1 || {
    echo automake not found
    exit 1
}

automake --add-missing --copy --gnu

echo autoconf...
(autoconf --version) < /dev/null > /dev/null 2>&1 || {
    echo autoconf not found
    exit 1
}

autoconf

echo ready to configure

exit 0
