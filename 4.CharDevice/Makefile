obj-m += char_dev.o

LKM_NAME = char_dev

.PHONE: all clean load unload

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

load:
	sudo insmod $(LKM_NAME).ko
	sudo dmesg -c

unload:
	sudo rmmod $(LKM_NAME)
	sudo dmesg -c

create_device: load
	sudo mknod /dev/$(LKM_NAME) c 250 0
	sudo chmod a+rw /dev/$(LKM_NAME)

remove_device: unload
	sudo rm /dev/$(LKM_NAME)

