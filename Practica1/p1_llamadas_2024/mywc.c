//P1-SSOO-23/24
//Pablo Gradolph Oliva - NIA: 100458456

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){

	int fd;
    int num_lines = 0, num_words = 0, num_bytes = 0;
    int in_word = 0;
    char ch;
    ssize_t read_bytes;

	// If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error and return -1
	if(argc < 2){
		printf("Too few arguments\n");
		return -1;
	}

	// We try to open the file
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
    	printf("Error opening file '%s': %s\n", argv[1], strerror(errno));
        return -1;
    }

	// Read the file character by character
    while ((read_bytes = read(fd, &ch, 1)) > 0) {
        
        num_bytes++;
        // If we find a line break, we increment the line counter
        if (ch == '\n') {
            num_lines++;
        }

        // Check if the character is a space or a tab with the isspace function.
        if (isspace((unsigned char)ch)) {
            
            // If we were on a word, we incremented the word counter and exited the word.
            if (in_word) {
                num_words++;
                in_word = 0;
            }	

        } else {
            // If the character is not a space, and we are not in a word, then we enter a word
            if (!in_word) {
                in_word = 1;
            }
        }
    }

    // Correct word count even when file does not end in space or line break.
    if (read_bytes != -1 && in_word) {
        num_words++;
    }	

	close(fd);
	printf("%d %d %d %s\n", num_lines, num_words, num_bytes, argv[1]);
    
	return 0;
}