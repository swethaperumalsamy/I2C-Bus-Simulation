#ifndef MASTER_H
#define MASTER_H

typedef struct
{
    int id;

} Master;

void send_address(int address);
void send_data(int data);

void receive_ack();
void receive_nack();

#endif
