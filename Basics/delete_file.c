#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* File_Name = "example.txt";

    if (unlink(File_Name) == -1) {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }

    printf("File deleted successfully: %s\n", File_Name);

    return 0;
}
