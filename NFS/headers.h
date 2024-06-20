#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define KBits 1024
#define Success 1
#define Failure 0
#define Other_y 2
#define U_Client 00
#define U_Naming 01
#define U_Storag 02

// Port Numbers for servers
#define C_SERVER_PORT 5000
#define N_SERVER_PORT 6000
#define S_SERVER_PORT 7000

// IP Addresses for servers
#define C_SERVER_IP "127.0.0.1"
#define N_SERVER_IP "127.0.0.1"
#define S_SERVER_IP "127.0.0.1"

// Few Important Structs regarding messages
struct Message {
    int Port_Number;
    char* IP_Address;
    int user_type;
};
typedef struct Message Standard_Details;

// Important typedef recasts
typedef struct sockaddr Socket_Address;

// Functions
void print_s(char* Message, int status_code);