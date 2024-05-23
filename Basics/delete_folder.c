#include <unistd.h>
#include <stdio.h>

int main() {
    const char *folderName = "new_folder";

    // Using the rmdir system call
    int result = rmdir(folderName);

    if (result == 0) {
        printf("Folder deleted successfully\n");
    } else {
        perror("Error deleting folder");
    }

    return 0;
}
