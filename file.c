#include <stdio.h>
#include <stdlib.h>

int read_file(char *filename, char **content)
{
	char *buffer = 0;
	int length = 0;
	int bytes_read = 0;
	FILE *file_handler = fopen(filename, "rb");

	if (file_handler) {
		fseek(file_handler, 0, SEEK_END);
		length = ftell(file_handler);
		fseek(file_handler, 0, SEEK_SET);
		buffer = malloc(length + 1);
		if (buffer) {
			bytes_read = fread(buffer, 1, length, file_handler);
		}
		fclose(file_handler);
	}

	buffer[bytes_read] = '\0';
	(*content) = buffer;

	return bytes_read;
}
