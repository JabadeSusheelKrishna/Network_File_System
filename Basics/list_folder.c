#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    const char *folderName = "new_folder";  // Change this to the folder you want to list
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    dir = opendir(folderName);
    if (dir == NULL) {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    // Read and print the contents of the directory
    printf("Contents of folder %s:\n", folderName);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    if (closedir(dir) == -1) {
        perror("Error closing directory");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
