obj-m := src/main.o
KDIR := /lib/modules/$(shell uname -r)/build

default: 
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules