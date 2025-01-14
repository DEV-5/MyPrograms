obj-m := simple_char_driver.o
KDIR=/lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(make) -C $(KDIR) M=$(PWD) clean
