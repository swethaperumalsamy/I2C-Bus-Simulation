#ifndef FIFO_SLAVE_H
#define FIFO_SLAVE_H

typedef struct
{
    int address;

    int data[10];

    int front;

    int rear;

} FIFO;

void fifo_init(FIFO *fifo,
               int address);

void enqueue(FIFO *fifo,
             int value);

void dequeue(FIFO *fifo);

#endif
