#include "headers.h"
#include "colours.h"

int main()
{
    Connection_Details details;
    details.port = 5000;
    strcpy(details.IP_address, "127.0.0.3");
    details = Establish_Connection_as_Server(details);

    printf(GRN "\n --- Server Established --- \n" reset);

    while (1)
    {
        details = Accept_Connection(details);

        printf(BLU "\n--- Client Found ---\n" reset);
        sleep(1);

        char Buffer[100];
        recv(details.Comm_socket, Buffer, 100, 0);
        printf(YEL "\n[***] %s [***]\n" reset, Buffer);
        sleep(1);

        send(details.Comm_socket, "We Got Your Message", 19, 0);
        sleep(1);

        close(details.Comm_socket);
    }
}