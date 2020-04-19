obj-m += module_args.o

LKM_NAME = module_args.ko

.PHONE: all clean load unload

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

load:
	sudo insmod $(LKM_NAME) param_value=100 param_msg="arg_msg"
	sudo dmesg -c

unload:
	sudo rmmod $(LKM_NAME)
	sudo dmesg -c
