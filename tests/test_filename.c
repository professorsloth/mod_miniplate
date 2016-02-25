#include <stdlib.h>
#include <check.h>

#include "../filename.h"

START_TEST (test_can_figure_out_template_filename_from_content_filename)
{
	char *string;

	string = get_template_filename("/var/www/article.html");

	ck_assert_str_eq(string, "/var/www/_base.html");
}
END_TEST

Suite * make_filename_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Filename");

	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_can_figure_out_template_filename_from_content_filename);
	suite_add_tcase(s, tc_core);

	return s;
}

