#ifndef LIFO_SLAVE_H
#define LIFO_SLAVE_H

typedef struct
{
    int address;

    int data[10];

    int top;

} LIFO;

void lifo_init(LIFO *lifo,
               int address);

void push(LIFO *lifo,
          int value);

void pop(LIFO *lifo);

#endif
