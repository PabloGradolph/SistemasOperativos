#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_BUFFER 512


int main(int argc, char **argv){

	int fd1, fd2;
	char buffer[MAX_BUFFER];

	if (argc != 3){
		printf("Numero de parametros incorrecto\n");
		return -1;
	}

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0){
		printf("No se puede abrir el fichero %s\n", argv[1]);
		return -1;
	}

	fd2 = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC);
	if (fd2 < 0){
		close(fd1);
		printf("No se puede abrir el fichero %s\n", argv[2]);
		return -1;
	}

	int leidos = 0;
	while ((leidos = read(fd1, buffer, MAX_BUFFER)) && (leidos > 0)){

		printf("%s\n", buffer);

		if (write(fd2, buffer, leidos) < 0){
			printf("No se puede escribir el fichero %s\n", argv[2]);
			close(fd1);
			close(fd2);
			return -1;
		}
	}

	close(fd1);
	close(fd2);

	return 0;
}