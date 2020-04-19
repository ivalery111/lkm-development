obj-m += hello.o

LKM_NAME = hello.ko

.PHONE: all clean load unload

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

load:
	sudo insmod $(LKM_NAME)
	sudo dmesg -c

unload:
	sudo rmmod $(LKM_NAME)
	sudo dmesg -c
