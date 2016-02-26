#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bstrlib/bstrlib.h"

char* replace_by_keyword(const char* keyword, const char* template_string, const char* string_to_inject)
{
	char* output;

	bstring b_keyword = bfromcstr(keyword);
	bstring b_replaced = bfromcstr(template_string);
	bstring b_string_to_inject = bfromcstr(string_to_inject);
	bfindreplace(b_replaced, b_keyword, b_string_to_inject, 0);

	output = bstr2cstr(b_replaced, '\0');

	return output;
}

