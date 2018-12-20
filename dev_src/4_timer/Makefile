obj-m +=timer.o
KERDIR = /home/fish/linux_dev_dp/kernel/linux-3.5/ 

all:
	make -C $(KERDIR) SUBDIRS=$(PWD) modules
clean:
	make -C $(KERDIR) SUBDIRS=$(PWD) clean
