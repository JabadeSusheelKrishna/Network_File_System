#include "headers.h"

int main() {
    char* IP = N_SERVER_IP;
    int port = N_SERVER_PORT;

    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    print_s("Socker Created", Success);

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(IP);

    int n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(n < 0) {
        print_s("Binding Error", Failure); 
        exit(0);
    }
    print_s("Binding Done at port 6000", Success);

    listen(server_sock, 3);
    print_s("Listening ...", Success);

    while(1)
    {
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
        print_s("Client Connected", Success);

        bzero(buffer, 1024);
        recv(client_sock, buffer, sizeof(buffer), 0);
        print_s("Msg recieved from the client for menu", Success);

        bzero(buffer, 1024);
        strcpy(buffer, "Please tell any message to us in form of an option : ");
        send(client_sock, buffer, strlen(buffer), 0);

        bzero(buffer, 1024);
        recv(client_sock, buffer, sizeof(buffer), 0);
        print_s("Option recieved from the client", Success);

        // Process the Option
        if(buffer != "read" || buffer != "write")
        {
            // Send Work Done
        }
        else
        {
            // Send Standard Message
        }
    }
}