#include <stdio.h>

#include "../include/memory_slave.h"

int check_address(MemorySlave *slave,
                  int address)
{
    if(slave->address == address)
    {
        return 1;
    }

    return 0;
}

void write_memory(MemorySlave *slave,
                  int index,
                  int data)
{
    slave->memory[index] = data;

    printf("DATA WRITTEN : %d\n",
           data);
}

void read_memory(MemorySlave *slave,
                 int index)
{
    printf("DATA READ : %d\n",
           slave->memory[index]);
}
