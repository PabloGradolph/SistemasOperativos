//P1-SSOO-23/24
//Pablo Gradolph Oliva - NIA: 100458456

#include <stdio.h>		// Header file for system call printf
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>		// Header file for system calls opendir, readdir y closedir
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <limits.h>	


int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    char path[PATH_MAX];

    if (argc > 1) {
        // Attempts to open the directory specified as an argument
        dir = opendir(argv[1]);
        if (dir == NULL) {
            printf("Error opening the directory %s: %s\n", argv[1], strerror(errno));
            return -1;
        }

    } else {
        // Try to get the current working directory and open it
        if (getcwd(path, sizeof(path)) == NULL) {
            printf("Error getting current directory: %s\n", strerror(errno));
            return -1;
        }

        dir = opendir(path);
        if (dir == NULL) {
            printf("Error opening current directory: %s\n", strerror(errno));
            return -1;
        }
    }

    // Read and display directory entries
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}

