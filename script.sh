#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Uso: bash $0 <arquivo_de_entrada> <CPU>"
    exit 1
fi

METRICA="FLOPS_DP"
CPU="$2"
ARQUIVO="$1"

echo "performance" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor

./perfSL < "$ARQUIVO"

for k in $METRICA
do
    likwid-perfctr -C "${CPU}" -g "${k}" -m ./perfSL < "$ARQUIVO" | grep -E 'Region | *DP MFLOP/s' | grep -v 'AVX DP MFLOP/s' | grep -v 'Region Info'
done

echo "powersave" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor