#include<linux/module.h>
#include "ring_buffer.c"
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BINDU SRI");
MODULE_DESCRIPTION("RING BUFFER MODULE");

struct ring_buffer* my_ring;

static int __init ring_buffer_init(void){
 my_ring=init_ring_buffer(5);
 pr_info("Ring buffer initialized\n");
 return 0;
 }
 
 static void __exit ring_buffer(void){
  cleanup(my_ring);
  pr_info("ring buffer module exiting\n");
  }
  module_init(ring_buffer_init);
  module_exit(ring_buffer);
