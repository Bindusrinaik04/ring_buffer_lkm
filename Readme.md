# Loadable Kernel Module
## _Assignment-5[Part:2]_
## Question : Objective: To create a Linux Kernel Module (LKM) that utilizes a ring/circular buffer (https://en.wikipedia.org/wiki/Circular_buffer) data structure for efficient data storage and retrieval within the kernel.

### Some Information about the Loadable Kernel Module including basic commands
- LKM is an object file that contains code to extend the running kernel of an operating system,they can be loaded dynamically.
- Kernel Module Structure:
    1. Kernel modules have a .ko file extension.
    2. They contain initialization and cleanup functions (init_module and cleanup_module) that are called when the module is loaded and unloaded, respectively.
- The steps that i followed to complete this assignment are listed down in order.

#### Step 1:
Creating the Shell file and executing it.
> gedit ring_buffer.sh
>chmod +x ring_buffer.sh
>sudo ./ring_buffer.sh

#### step 2:
Inside the ring_buffer_module directory creating an d editing the source files
> gedit ring_buffer.c

#### step 3:
write the Makefile for this module which consists of the following content :
> obj-m += ring_buffer_lkm.o
 all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
 clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

#### step 4 :compiling and loading the module
As done in the first part of the assignment : compile and load the module using the following commands
> make

After successfully compiling the hello.c file,the directory will now have multiple file.Among them the file "hello.ko" is our loadable kernel module file which we use to load and unload it to the running kernel.
Loadind the module :
 
> sudo insmod ring_buffer_lkm.ko

#### Step 5: check the module
after successfully loading the module to see the print statement.Look in to the system logs using 'dmesg'
> sudo dmesg | tail

You can also verify it using 'lsmod' command
> lsmod | gerp hello

#### Step 6: Unloading Module
To unload the Module type the following command on terminal
> sudo rmmod hello.ko

Similar to loading,you can check if the module is loaded or not using 'lsmod' or 'dmesg' commands with 'sudo' priviliges
#### step 7: creating a test module
Now that you have verified the loading and unloading of the ring_buffer_lkm ,to test the working of the buffer create a test_program.c where the insert_data,retrieve_data and cleanup functions can be tested.
> touch test_program.c

##### content of the test_program is : 
 #include<linux/module.h>
 #include "ring_buffer.c"
 #include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BINDU SRI");
MODULE_DESCRIPTION("RING BUFFER MODULE Testing");

struct ring_buffer* my_ring_test;

static int __init test_ring(void){
 my_ring_test = init_ring_buffer(5);
 insert_data(my_ring_test,55);
 insert_data(my_ring_test,1);
 pr_info("Test module initialized");
 pr_info("retrived data from the buffer :%d\n",retrieve_data(my_ring_test));
 pr_info("retrived data from the buffer :%d\n",retrieve_data(my_ring_test));
 
 return 0;
 }
 
 static void __exit test_ring_exit(void){
 cleanup(my_ring_test);
 pr_info("test module exiting\n");
 }
 module_init(test_ring);
 module_exit(test_ring_exit);
 

#### Step 8: 
modify the  Makefile and adding the following commands to it.
> obj-m += ring_buffer_lkm.o
obj-m += test_program.o
all:
	[tab]make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	[tab]make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	
make sure that you object file name is same as your source file name.

 

#### Step 9:
After successfully compiling the hello.c file,the directory will now have multiple file.Among them the file "hello.ko" is our loadable kernel module file which we use to load and unload it to the running kernel.
Loadind the module :
> sudo insmod ring_buffer_lkm.ko
sudo insmod test_program.ko

#### Step 7: Loading the module
after successfully loading the module to see the print statement.Look in to the system logs using 'dmesg'
> sudo dmesg | tail

You can also verify it using 'lsmod' command
> lsmod | grep ring_buffer
lsmod | grep test_program

#### Step 8: Unloading Module
To unload the Module type the following command on terminal
> sudo rmmod ring_buffer_lkm.ko
sudo rmmod test_program.ko

Similar to loading,you can check if the module is loaded or not using 'lsmod' or 'dmesg' commands with 'sudo' priviliges

   
