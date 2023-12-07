#include "headers.h"
#include "userdefs.h"
#include "colours.h"

// This Code provides the Port Number to the Client to connect with the naming server

int main()
{
    Connection_Details details;
    details.port = DHCP_PORT;
    strcpy(details.IP_address, Local_IP);
    details = Establish_Connection_as_Server(details);

    printf(GRN"\n--- Connection Established as Server ---\n"reset);

    int client_port = i_client_port;

    while(1)
    {
        details = Accept_Connection(details);
        printf(BLU"\n--- New Connection Found ---\n"BLU);

        // recieve the message from the server
        char Buffer[10];
        recv(details.Comm_socket, Buffer, sizeof(Buffer), 0);

        // send his port number to the client
        send(details.Comm_socket, &client_port, sizeof(client_port), 0);

        printf(BLU"\n[-] Port given to the Client [-]\n"reset);
        client_port++;

        close(details.Comm_socket);
    }
}