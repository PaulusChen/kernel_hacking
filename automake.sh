#!/bin/sh

# ./automake.sh ~/Documents/linux/

KERNEL_PATH=$1
# make -C ${KERNEL_PATH} SUBDIRS=$PWD modules
make -C ${KERNEL_PATH} M=$PWD modules
