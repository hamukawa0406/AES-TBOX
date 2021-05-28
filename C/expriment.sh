#!/bin/bash
echo "using tbox"
for i in {1..10}
do
    gtime -f "%E  %M kB" ./AES-TBOX -t tbox
done

