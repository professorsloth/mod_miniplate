#include <stdlib.h>
#include <check.h>

#include "../miniplate.h"

START_TEST (test_can_count_no_occurrences)
{
	int count;

	count = count_occurrences("team", "i");

	ck_assert_int_eq(count, 0);
}
END_TEST

START_TEST (test_can_count_single_occurrence)
{
	int count;

	count = count_occurrences("hello world", "hello");

	ck_assert_int_eq(count, 1);
}
END_TEST

START_TEST (test_can_count_multiple_occurrences)
{
	int count;

	count = count_occurrences("look down, look down\ndon't look 'em in the eye", "look");

	ck_assert_int_eq(count, 3);
}
END_TEST

Suite * make_validation_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Validation");

	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_can_count_no_occurrences);
	tcase_add_test(tc_core, test_can_count_single_occurrence);
	tcase_add_test(tc_core, test_can_count_multiple_occurrences);
	suite_add_tcase(s, tc_core);

	return s;
}

