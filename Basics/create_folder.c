#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <userperm.h>

int main() {
    const char *folderName = "new_folder";
    mode_t mode = BASIC_FOLDER_PERM;

    // Using the mkdir system call
    int result = mkdir(folderName, mode);

    if (result == 0) {
        printf("Folder created successfully\n");
    } else {
        perror("Error creating folder");
    }

    return 0;
}
