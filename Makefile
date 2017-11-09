obj-m += simple_modules.o

KDIR = /usr/src/linux-headers-3.16.0-4-686-pae

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order .tmp*
