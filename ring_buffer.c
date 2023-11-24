#include<linux/slab.h>

/* The <linux/slab> header,which provides memory allocation functions like kmalloc and kfree. These functions are used to allocate and deallocate memory in the kernel.*/

struct ring_buffer {
 int* buffer;
 int size;
 int head;
 int tail;
 };

/* Defines a structure named ring_buffer that represents the circular buffer. It contains:
    int* buffer: A pointer to an array that will hold the data.
    int size: The size of the buffer.
    int head: The index where the next data element will be inserted.
    int tail: The index where the next data element will be retrieved.*/

struct ring_buffer* init_ring_buffer(int size) {
struct ring_buffer* r = kmalloc(sizeof(struct ring_buffer),GFP_KERNEL);
r->buffer = kmalloc(size * sizeof(int),GFP_KERNEL);
r->size =size;
r->head =0;
 r->tail =0;
 return r;
 }
 /*initializes a new ring_buffer structure.
It allocates memory for the structure and the buffer array using kmalloc.
It sets the size, head, and tail to initial values.
The GFP_KERNEL flag indicates that the memory allocation is happening in the kernel context.*/

void insert_data(struct ring_buffer* r,int data){
r->buffer[r->head]=data;
r->head =(r->head+1)%r->size;
}
/*adds new element to the ring buffer,writing tthe data at the current head index and incrementing the head index*/

int retrieve_data(struct ring_buffer* r){
 int data = r->buffer[r->tail];
 r->tail = (r->tail+1)%r->size;
 return data;
 }
 /* gets the data from the current tail index*/
 
 void cleanup (struct ring_buffer* r)
 {
  kfree(r->buffer);
  kfree(r);
  }
