#include <stdio.h>

#include "../include/master.h"

void send_address(int address)
{
    printf("MASTER SENT ADDRESS : 0x%x\n",
           address);
}

void send_data(int data)
{
    printf("MASTER SENT DATA : %d\n",
           data);
}

void receive_ack()
{
    printf("MASTER RECEIVED ACK\n");
}

void receive_nack()
{
    printf("MASTER RECEIVED NACK\n");
}
