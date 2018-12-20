KERDIR = /home/fish/linux_kernel/kernel/linux-3.5/ 
obj-m += platform.o

all:
	make -C $(KERDIR) SUBDIRS=$(PWD) modules
clean:
	make -C $(KERDIR) SUBDIRS=$(PWD) clean
