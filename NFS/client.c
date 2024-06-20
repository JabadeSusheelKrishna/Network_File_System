#include "headers.h"

int setup_socket()
{
    int temp = socket(AF_INET, SOCK_STREAM, 0);
    if(temp < 0)
    {
        perror("[-] Socket Creattion Error {See setup_socket function}");
        exit(1);
    }
    print_s("TCP Socket Setup Done", Success);
    return temp;
}

struct sockaddr_in setup_addr(int port_number, char* ip_address)
{
    struct sockaddr_in addr;
    memset(&addr, '\0', sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = port_number;
    addr.sin_addr.s_addr = inet_addr(ip_address);
    return addr;
}

int main()
{
    char* IP = C_SERVER_IP;
    int port = C_SERVER_PORT;
    char buffer[KBits];

    /* First we need to send a message from the Naming Server
    and Get a Menu message from the naming server for allowed
    operations. and Then we need to Select an Option and send
    it back to the Naming Server.
    
    [Client {C}] ===req==> [Naming {S}]     :-  Hi send me menu
    [Client {C}] <--res--- [Naming {S}]     :-  Ok, take it :)
    
    [Client {C}] ===req==> [Naming {S}]     :-  Do this Operation
    [Client {C}] <--res--- [Naming {S}]     :-  Done, take it
    ---------------------------------------------------------------
    */
    int sock = setup_socket();
    struct sockaddr_in addr = setup_addr(port, IP);

    // Connect with the Main Server
    connect(sock, (Socket_Address*) &addr, sizeof(addr));
    print_s("Connected to the Naming Server", Success);

    // We need to send our details as message
    Standard_Details first_message;
    first_message.IP_Address = IP;
    first_message.Port_Number = port;
    first_message.user_type = U_Client;

    send(sock, &first_message, sizeof(first_message), 0);
    print_s("=> Standard Details to the Naming Server", Success);

    bzero(buffer, 1024);
    recv(sock, buffer, sizeof(buffer), 0);
    print_s(buffer, Other_y);

    // We need to select an option and send it
    bzero(buffer, 1024);
    scanf("%s", buffer);
    send(sock, buffer, strlen(buffer), 0);
    print_s("=> Option to the Naming Server", Success);

    if(strcmp(buffer, "read") != 0 || strcmp(buffer, "write") != 0)
    {
        // We Need to recieve Message as a String
        bzero(buffer, 1024);
        recv(sock, buffer, strlen(buffer), 0);
        print_s(buffer, Other_y);

        close(sock);
    }
    else
    {
        // We need to recieve Message as a Standard Message
        Standard_Details* rec_message = (Standard_Details*) malloc (sizeof(Standard_Details));
        recv(sock, rec_message, sizeof(rec_message), 0);

        /* Now the message which we received from Naming
        Server is the details of the Storage server wher
        our file is Located. We can perform read and wri
        operation here. 
        
        [Client {C}] ===req==> [Storage {S}]     :-  Do This Operation
        [Client {C}] <--res--- [Storage {S}]     :-  Ok Done.
        */
        printf(YEL "<=> %s\n", rec_message->IP_Address);
        printf("<=> %d \n" WHT, rec_message->Port_Number);

        close(sock);
    }
    printf("\n-----------------------------------\n");
    return 0;
}