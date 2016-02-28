#include <stdlib.h>
#include <check.h>

#include "../miniplate.h"

START_TEST (test_can_read_file_into_string)
{
	char *string;
	int bytes_read;

	bytes_read = read_file("fixtures/hello.txt", &string);

	ck_assert_int_eq(bytes_read, 6);
	ck_assert_str_eq(string, "hello\n");
}
END_TEST

Suite * make_file_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("File");

	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_can_read_file_into_string);
	suite_add_tcase(s, tc_core);

	return s;
}

