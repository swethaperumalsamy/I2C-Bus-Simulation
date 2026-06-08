#ifndef I2C_BUS_H
#define I2C_BUS_H

#define MEMORY_ADDRESS 0x10
#define FIFO_ADDRESS   0x20
#define LIFO_ADDRESS   0x30

typedef struct
{
    int scl;
    int sda;
    int busy;
    int current_master;

} I2CBus;

void start_condition(I2CBus *bus, int master_id);
void stop_condition(I2CBus *bus);

#endif
