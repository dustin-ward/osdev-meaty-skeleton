#!/bin/sh
set -e
#. ./iso.sh
#qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom myos.iso

. ./build.sh
qemu-system-$(./target-triplet-to-arch.sh $HOST) -kernel sysroot/boot/shrbos.kernel
