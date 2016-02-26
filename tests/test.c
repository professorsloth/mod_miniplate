#include <stdlib.h>
#include <check.h>

#include "tests.h"

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	sr = srunner_create(make_file_suite());
	srunner_add_suite(sr, make_filename_suite());
	srunner_add_suite(sr, make_validation_suite());
	srunner_add_suite(sr, make_templating_suite());

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

