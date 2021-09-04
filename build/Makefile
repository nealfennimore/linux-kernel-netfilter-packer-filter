MODULE_NAME = packet_filter

obj-m := $(MODULE_NAME).o
# ccflags-y := $(ccflags-y) -xc -E -v
KERNEL_DIR := /lib/modules/$(shell uname -r)/build

default:
	cp $$PWD/src/netfilter/$(MODULE_NAME).c $$PWD/build/$(MODULE_NAME).c
	$(MAKE) -C $(KERNEL_DIR) M=$$PWD/build modules

bclean:
	rm $$PWD/build/$(MODULE_NAME).c
	$(MAKE) -C $(KERNEL_DIR) M=$$PWD/build clean

clean: uninstall bclean

info:
	-lsmod | grep $(MODULE_NAME)

install:
	-sudo insmod build/$(MODULE_NAME).ko

uninstall:
	-sudo rmmod $(MODULE_NAME)
