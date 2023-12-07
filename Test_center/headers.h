#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <dirent.h>
#include <semaphore.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/stat.h>
// ^^^^ HEADERS REQUIERED TO RUN ^^^^

#define KB_1 1024

// ************** NETWORK CONNECTION HEADERS *****************

struct Connection_Details
{
	int port;			// Port number on which both server and client gets connected
	char IP_address[15];	// IP address of client / server
	int Server_socket;	// return value of socket function for server
	int Client_socket;	// return value of socket function for client
	int Comm_socket;		// Socket on which communication should happen usually client socket
};

typedef struct Connection_Details Connection_Details;
typedef struct Connection_Details* Ptr_Conn_Dets;

Connection_Details Establish_Connection_as_Server (Connection_Details Details);

Connection_Details Establish_Connection_as_Client (Connection_Details Details);

Connection_Details Accept_Connection (Connection_Details Details);

void Close_connection (Connection_Details Details);