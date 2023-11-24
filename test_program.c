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
 
