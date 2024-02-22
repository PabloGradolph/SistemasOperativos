//P1-SSOO-23/24
//Pablo Gradolph Oliva - NIA: 100458456

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[]){

	DIR *dir;
    struct dirent *entry;

	/* If less than three arguments (argv[0] -> program, argv[1] -> directory to search, argv[2] -> file to find) print an error y return -1 */
	if(argc < 3){
		printf("Too few arguments\n");
		return -1;
	}

	// Try to open the specified directory
	dir = opendir(argv[1]);
	if (dir == NULL) {
		printf("Error opening the directory %s: %s\n", argv[1], strerror(errno));
		return -1;
	}

	// Read each directory entry
	while ((entry = readdir(dir)) != NULL) {
		// Compare the input name with the given file name
		if (strcmp(entry->d_name, argv[2]) == 0) {
			// If it finds a match, it prints the message and closes the directory
			printf("File %s is in directory %s\n", argv[2], argv[1]);
			closedir(dir);
			return 0;
		}
	}	

	// If the file is not found, it prints the corresponding message
	printf("File %s is not in directory %s\n", argv[2], argv[1]);

	// Close the directory
	closedir(dir);

	return 0;
}