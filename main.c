#include <stdio.h>

#include "../include/i2c_bus.h"
#include "../include/master.h"
#include "../include/memory_slave.h"
#include "../include/fifo_slave.h"
#include "../include/lifo_slave.h"

int main()
{
    I2CBus bus;

    bus.scl = 1;
    bus.sda = 1;
    bus.busy = 0;
    bus.current_master = -1;

    Master master1;

    master1.id = 1;

    MemorySlave memory1;

    memory1.address = MEMORY_ADDRESS;

    FIFO fifo1;

    fifo_init(&fifo1,
              FIFO_ADDRESS);

    LIFO lifo1;

    lifo_init(&lifo1,
              LIFO_ADDRESS);

    int choice;

    int data;

    while(1)
    {
        printf("\n");

        printf("===== I2C MENU =====\n");

        printf("1. Memory Write\n");

        printf("2. Memory Read\n");

        printf("3. FIFO Enqueue\n");

        printf("4. FIFO Dequeue\n");

        printf("5. LIFO Push\n");

        printf("6. LIFO Pop\n");

        printf("7. Exit\n");

        printf("Enter Choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                start_condition(&bus,
                                master1.id);

                send_address(MEMORY_ADDRESS);

                if(check_address(&memory1,
                                 MEMORY_ADDRESS))
                {
                    receive_ack();

                    printf("Enter Data : ");

                    scanf("%d",
                          &data);

                    send_data(data);

                    write_memory(&memory1,
                                 0,
                                 data);
                }

                stop_condition(&bus);

                break;

            case 2:

                start_condition(&bus,
                                master1.id);

                send_address(MEMORY_ADDRESS);

                if(check_address(&memory1,
                                 MEMORY_ADDRESS))
                {
                    receive_ack();

                    read_memory(&memory1,
                                0);
                }

                stop_condition(&bus);

                break;

            case 3:

                start_condition(&bus,
                                master1.id);

                send_address(FIFO_ADDRESS);

                receive_ack();

                printf("Enter Data : ");

                scanf("%d",
                      &data);

                enqueue(&fifo1,
                        data);

                stop_condition(&bus);

                break;

            case 4:

                start_condition(&bus,
                                master1.id);

                send_address(FIFO_ADDRESS);

                receive_ack();

                dequeue(&fifo1);

                stop_condition(&bus);

                break;

            case 5:

                start_condition(&bus,
                                master1.id);

                send_address(LIFO_ADDRESS);

                receive_ack();

                printf("Enter Data : ");

                scanf("%d",
                      &data);

                push(&lifo1,
                     data);

                stop_condition(&bus);

                break;

            case 6:

                start_condition(&bus,
                                master1.id);

                send_address(LIFO_ADDRESS);

                receive_ack();

                pop(&lifo1);

                stop_condition(&bus);

                break;

            case 7:

                return 0;

            default:

                printf("INVALID CHOICE\n");
        }
    }

    return 0;
}
