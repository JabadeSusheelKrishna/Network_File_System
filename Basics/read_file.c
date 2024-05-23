#include <fcntl.h>  // Used for File System Calls
#include <unistd.h> // Used for Basic System Calls
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main() {

    char *File_name = "example.txt";

    int fd = open(File_name, O_RDONLY);     // Here we are Opening the File First by describing the Permission

    /*IMPORTANT : fd means File Descriptor which is an integer value
    if you are opening a file with some permissions then OS assigns
    you an integer. if return value is "-1" it means that file opening
    is unsuccessful. Even File Permissions are Integers. O_RDONLY
    corresponds to 00.*/

    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];   // Here The data gets stored
    ssize_t bytesRead;

    /* Read function returns -1 is unsuccessful else it
    returns how many bytes it read. if it is 0 then it means
    it had completed reading file.*/

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytesRead) != bytesRead) {
            perror("Error writing to stdout");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytesRead == -1) {
        perror("Error reading file");
    }

    close(fd);
    return 0;
}
