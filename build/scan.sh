#! /bin/sh
# scan - scan source files for exported functions
# Copyright (C) Romain Lievin 2003
# Contact: roms@tilp.info
#

SRC=../src
DST=tifiles.def

echo "Parsing..."

rm -f $DST
echo "LIBRARY tifiles.dll" >> $DST
echo "EXPORTS" >> $DST
echo "" >> $DST

for I in $SRC/*.c ; do \
    echo $I
    cat $I | awk -f scan.awk dst=$DST
done

echo "Done !"
