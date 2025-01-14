obj-m := keyboard_interrupt_basic.o
KDIR=/lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(make) -C $(KDIR) M=$(PWD) clean
