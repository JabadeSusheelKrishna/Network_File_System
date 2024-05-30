#include "headers.h"

int setup_socket()
{
    int temp = socket(AF_INET, SOCK_STREAM, 0);
    if(temp < 0)
    {
        perror("[-] Socket Creattion Error {See setup_socket function}");
        exit(1);
    }
    printf(RED "[+] TCP Socket Setup Done" WHT);
}

struct sockaddr_in setup_addr(int port_number, char** ip_address)
{
    struct sockaddr_in addr;
    memset(&addr, '\0', sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = port_number;
    addr.sin_addr.s_addr = inet_addr(*ip_address);
}

int main()
{
    char* IP = "127.0.0.1";
    int port = 5000;
    char buffer[1024];

    int sock = setup_socket();
    struct sockaddr_in addr = setup_addr(port, &IP);
}