#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <gumbo.h>

char* get_last_h1(GumboNode* node) {
	char* result = "";
	int i = 0;

	if (node->type != GUMBO_NODE_ELEMENT) {
		return "";
	}

	if (node->v.element.tag == GUMBO_TAG_H1) {
		GumboNode* text_node = node->v.element.children.data[0];
		if (text_node->type == GUMBO_NODE_TEXT) {
			return (char*)text_node->v.text.text;
		}
	}

	GumboVector* children = &node->v.element.children;
	for (i = 0; i < children->length; ++i) {
		char* heading = get_last_h1(children->data[i]);
		if (strcmp(heading, "") != 0) {
			result = heading;
		}
	}

	return strdup(result);
}

char* find_last_heading(char* initial_document) {
	char* input = strdup(initial_document);
	int input_length = strlen(input);

	GumboOutput* output = gumbo_parse_with_options(&kGumboDefaultOptions, input, input_length);
	const char* heading = get_last_h1(output->root);

	gumbo_destroy_output(&kGumboDefaultOptions, output);
	free(input);

	return (char*)heading;
}

