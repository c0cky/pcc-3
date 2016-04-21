#!/bin/bash
make clean
make
./pcc3 < T2L100_ok.c > t.s
#gcc -m32 t.s lib85.c
#./a.out < $1
