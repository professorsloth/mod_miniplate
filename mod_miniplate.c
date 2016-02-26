#include "httpd.h"
#include "http_log.h"
#include "http_core.h"
#include "http_protocol.h"
#include "http_request.h"
#include "apr_strings.h"
#include "string.h"
#include "stdio.h"

#include "file.h"
#include "filename.h"
#include "templating.h"
#include "validation.h"

static int miniplate_handler(request_rec*);
static void register_hooks(apr_pool_t*);

module AP_MODULE_DECLARE_DATA miniplate_module = {
	STANDARD20_MODULE_STUFF,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	register_hooks,
};

static int miniplate_handler(request_rec *r)
{
	char *base_template_filename = 0;
	char *template_content = 0;
	int template_length = 0;
	char *content_file_content = 0;
	int content_file_length = 0;
	int replacement_occurrences = 0;
	char* output;

	if (!r->handler || strcmp(r->handler, "miniplate")) {
		return DECLINED;
	}

	base_template_filename = get_template_filename(r->filename);
	template_length = read_file(base_template_filename, &template_content);
	content_file_length = read_file(r->filename, &content_file_content);

	if (template_length < 1) {
		return HTTP_INTERNAL_SERVER_ERROR;
	}

	if (content_file_length < 1) {
		return HTTP_NO_CONTENT;
	}

	output = replace_by_keyword("(content)", template_content, content_file_content);
	output = replace_by_keyword("(path)", output, r->parsed_uri.path);

	ap_set_content_type(r, "text/html");
	ap_rputs(output, r);

	return OK;
}

static void register_hooks(apr_pool_t *pool)
{
	ap_hook_handler(miniplate_handler, NULL, NULL, APR_HOOK_LAST);
}

