#include <stdlib.h>
#include <check.h>

#include "../miniplate.h"

START_TEST (test_replaces_keyword_with_provided_content)
{
	const char* keyword = "(content)";
	const char* template_string = "Hello, (content)!";
	const char* string_to_inject = "world";
	char* replaced_string = NULL;

	replaced_string = replace_by_keyword(keyword, template_string, string_to_inject);

	ck_assert_str_eq(replaced_string, "Hello, world!");
}
END_TEST

Suite * make_templating_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Templating");

	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_replaces_keyword_with_provided_content);
	suite_add_tcase(s, tc_core);

	return s;
}

