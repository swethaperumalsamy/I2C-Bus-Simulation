#include <stdio.h>

#include "../include/lifo_slave.h"

void lifo_init(LIFO *lifo,
               int address)
{
    lifo->address = address;

    lifo->top = -1;
}

void push(LIFO *lifo,
          int value)
{
    if(lifo->top == 9)
    {
        printf("LIFO OVERFLOW\n");

        return;
    }

    lifo->top++;

    lifo->data[lifo->top] = value;

    printf("PUSHED : %d\n",
           value);
}

void pop(LIFO *lifo)
{
    if(lifo->top == -1)
    {
        printf("LIFO UNDERFLOW\n");

        return;
    }

    printf("POPPED : %d\n",
           lifo->data[lifo->top]);

    lifo->top--;
}
