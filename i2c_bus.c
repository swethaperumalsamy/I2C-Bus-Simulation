#include <stdio.h>

#include "../include/i2c_bus.h"

void start_condition(I2CBus *bus, int master_id)
{
    if(bus->busy == 1)
    {
        printf("BUS BUSY\n");

        printf("MASTER %d LOST ARBITRATION\n",
               master_id);

        return;
    }

    bus->busy = 1;

    bus->current_master = master_id;

    printf("MASTER %d WON ARBITRATION\n",
           master_id);

    printf("START CONDITION\n");
}

void stop_condition(I2CBus *bus)
{
    printf("MASTER %d RELEASED BUS\n",
           bus->current_master);

    bus->busy = 0;

    bus->current_master = -1;

    printf("STOP CONDITION\n");
}
