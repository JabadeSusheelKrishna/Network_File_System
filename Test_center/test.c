#include "headers.h"
#include "colours.h"

int main()
{
    Connection_Details details;
    details.port = 5000;
    strcpy(details.IP_address, "127.0.0.1");

    details = Establish_Connection_as_Client(details);
    sleep(1);

    printf(GRN"\n--- Connection Started with Server ---\n"reset);

    send(details.Comm_socket, "Hello_This_is_Client", 20, 0);
    sleep(1);

    char Buffer[100];
    recv(details.Comm_socket, Buffer, 100, 0);

    printf(YEL"\n[***] %s [***]\n"reset, Buffer);
    sleep(1);

    close(details.Comm_socket);
    printf(RED"\n --- Connection Closed --- \n"reset);

    return 0;
}