ifeq ($(KERNELRELEASE),)
PWD = $(shell pwd)

KERNEL_DIR = /home/fish/linux_dev_dp/kernel/linux-3.5/ 

modules:
	make -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean

else
obj-m += chardev.o 

endif
