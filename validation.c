#include <string.h>

int count_occurrences(char *string, const char *substring)
{
	int occurrences = 0;

	const char *next_string = string;

	while ((next_string = strstr(next_string, substring))) {
		occurrences++;
		next_string++;
	}

	return occurrences;
}

