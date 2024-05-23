#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char* File_Name = "example.txt";

    int fd = open(File_Name, O_WRONLY | O_TRUNC , S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    const char *data = "Hello, this is a test string to write to the file.\n";
    ssize_t bytesWritten = write(fd, data, strlen(data));

    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (bytesWritten != strlen(data)) {
        fprintf(stderr, "Partial write error\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}
