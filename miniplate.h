#include <stdbool.h>
#include <gumbo.h>

char* replace_by_keyword(const char*, const char*, const char*);
char* get_template_filename(char*);
int read_file(char*, char**);
bool find_heading(char*, char**);
char* find_last_heading(char*);

#define BASE_TEMPLATE_NAME "/_base.html"
