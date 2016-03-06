#include <libgen.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "miniplate.h"

char* get_template_filename(char *filename)
{
	char *base_template_abspath;
	const char * base_template_relpath = BASE_TEMPLATE_NAME;

	char *filename_copy = strdup(filename);
	char *this_directory = dirname(filename_copy);

	int length = strlen(this_directory) + strlen(base_template_relpath) + 1;

	base_template_abspath = malloc(length);
	snprintf(base_template_abspath, length, "%s%s", this_directory, base_template_relpath);

	return base_template_abspath;
}

