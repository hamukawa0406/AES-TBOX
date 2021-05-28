#!/bin/bash
echo "using sbox"
for i in {1..10}
do
    gtime -f "%E  %M kB" ./AES-TBOX -t sbox
done

