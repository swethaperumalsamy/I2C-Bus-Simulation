#include <stdio.h>

#include "../include/fifo_slave.h"

void fifo_init(FIFO *fifo,
               int address)
{
    fifo->address = address;

    fifo->front = 0;

    fifo->rear = -1;
}

void enqueue(FIFO *fifo,
             int value)
{
    if(fifo->rear == 9)
    {
        printf("FIFO OVERFLOW\n");

        return;
    }

    fifo->rear++;

    fifo->data[fifo->rear] = value;

    printf("ENQUEUED : %d\n",
           value);
}

void dequeue(FIFO *fifo)
{
    if(fifo->front > fifo->rear)
    {
        printf("FIFO UNDERFLOW\n");

        return;
    }

    printf("DEQUEUED : %d\n",
           fifo->data[fifo->front]);

    fifo->front++;
}
