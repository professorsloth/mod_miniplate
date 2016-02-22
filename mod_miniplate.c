#include "httpd.h"
#include "http_log.h"
#include "http_core.h"
#include "http_protocol.h"
#include "http_request.h"
#include "apr_strings.h"
#include "libgen.h"
#include "string.h"
#include "stdio.h"

static int miniplate_handler(request_rec*);
static void register_hooks(apr_pool_t*);
char* read_file(char*);
int count_occurrences(char*, const char*);

module AP_MODULE_DECLARE_DATA miniplate_module = {
	STANDARD20_MODULE_STUFF,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	register_hooks,
};

char* read_file(char *filename)
{
	char *buffer = 0;
	int length;
	FILE *f = fopen(filename, "rb");

	if (f) {
		fseek(f, 0, SEEK_END);
		length = ftell(f);
		fseek(f, 0, SEEK_SET);
		buffer = malloc(length);
		if (buffer) {
			fread(buffer, 1, length, f);
		}
		fclose(f);
	}

	return buffer;
}

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

static int miniplate_handler(request_rec *r)
{
	char *filename = 0;
	char *this_directory = 0;
	char *base_template_filename = 0;
	char *template_content = 0;
	char *file_content = 0;
	int replacement_occurrences = 0;

	if (!r->handler || strcmp(r->handler, "miniplate")) {
		return DECLINED;
	}

	filename = apr_pstrdup(r->pool, r->filename);
	this_directory = apr_pstrdup(r->pool, dirname(r->filename));
	base_template_filename = apr_pstrcat(r->pool, this_directory, "/_base.html", NULL);
	template_content = read_file(base_template_filename);
	file_content = read_file(filename);

	ap_set_content_type(r, "text/html");

	replacement_occurrences = count_occurrences(template_content, "%s");
	if (2 != replacement_occurrences) {
		return HTTP_INTERNAL_SERVER_ERROR;
	}

	ap_rprintf(r, template_content, r->parsed_uri.path, file_content);

	return OK;
}

static void register_hooks(apr_pool_t *pool)
{
	ap_hook_handler(miniplate_handler, NULL, NULL, APR_HOOK_LAST);
}

