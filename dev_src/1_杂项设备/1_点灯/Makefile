KERNELDIR = /home/fish/linux_dev_dp/kernel/linux-3.5/
PWD := $(shell pwd)

#kernel modules
obj-m := misc.o
misc_module-objs := misc.o


build: kernel_modules

kernel_modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.o *.ko *.cmd *.mod.* modules.order Module.symvers .tmp_versions
