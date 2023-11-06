#!/bin/bash

stage=$1

afl-fuzz -i ${stage}-indir/ -o ${stage}-outdir/ -x inputs.dict -- ./${stage}-softplc @@
