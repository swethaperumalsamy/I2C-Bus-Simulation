#ifndef MEMORY_SLAVE_H
#define MEMORY_SLAVE_H

typedef struct
{
    int address;

    int memory[256];

} MemorySlave;

int check_address(MemorySlave *slave,
                  int address);

void write_memory(MemorySlave *slave,
                  int index,
                  int data);

void read_memory(MemorySlave *slave,
                 int index);

#endif
