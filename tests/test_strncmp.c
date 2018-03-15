/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_strncmp.c
*/
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static int (*my_strncmp)(char *, char *, size_t) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_strncmp = dlsym(lib, "strncmp");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_strncmp = NULL;
}

Test(strncmp, ncmp1, .init = setup, .fini = teardown)
{
	cr_assert_eq(my_strncmp("TOP", "TOP", 3), strncmp("TOP", "TOP", 3));
	cr_assert_eq(my_strncmp("TOP", "TAP", 3), strncmp("TOP", "TAP", 3));
	cr_assert_eq(my_strncmp("TOP", "TOZ", 3), strncmp("TOP", "TOZ", 3));
	cr_assert_eq(my_strncmp("TAP", "TOP", 3), strncmp("TAP", "TOP", 3));
	cr_assert_eq(my_strncmp("TOZ", "TOP", 3), strncmp("TOZ", "TOP", 3));
	cr_assert_eq(my_strncmp("TOP", "TOP", 2), strncmp("TOP", "TOP", 2));
	cr_assert_eq(my_strncmp("TOP", "TAP", 2), strncmp("TOP", "TAP", 2));
	cr_assert_eq(my_strncmp("TOP", "TOZ", 2), strncmp("TOP", "TOZ", 2));
	cr_assert_eq(my_strncmp("TAP", "TOP", 2), strncmp("TAP", "TOP", 2));
	cr_assert_eq(my_strncmp("TOZ", "TOP", 2), strncmp("TOZ", "TOP", 2));
}

Test(strncmp, ncmp2, .init = setup, .fini = teardown)
{
	cr_assert_eq(my_strncmp("TOP", "TOP", 1), strncmp("TOP", "TOP", 1));
	cr_assert_eq(my_strncmp("TOP", "TAP", 1), strncmp("TOP", "TAP", 1));
	cr_assert_eq(my_strncmp("TOP", "TOZ", 1), strncmp("TOP", "TOZ", 1));
	cr_assert_eq(my_strncmp("TAP", "TOP", 1), strncmp("TAP", "TOP", 1));
	cr_assert_eq(my_strncmp("TOZ", "TOP", 1), strncmp("TOZ", "TOP", 1));
	cr_assert_eq(my_strncmp("TOP", "TOP", 4), strncmp("TOP", "TOP", 4));
	cr_assert_eq(my_strncmp("TOP", "TAP", 4), strncmp("TOP", "TAP", 4));
	cr_assert_eq(my_strncmp("TOP", "TOZ", 4), strncmp("TOP", "TOZ", 4));
	cr_assert_eq(my_strncmp("TAP", "TOP", 4), strncmp("TAP", "TOP", 4));
	cr_assert_eq(my_strncmp("TOZ", "TOP", 4), strncmp("TOZ", "TOP", 4));
	cr_assert_eq(my_strncmp("", "", 4), strncmp("", "", 4));
}
