/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_strcmp.c
*/
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static int (*my_strcmp)(char *, char *) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_strcmp = dlsym(lib, "strcmp");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_strcmp = NULL;
}

static int s(int val)
{
	if (val < 0)
		return (-1);
	if (val > 0)
		return (1);
	return (0);
}

Test(strcmp, match, .init = setup, .fini = teardown)
{
	cr_assert_eq(s(my_strcmp("TOP", "TOP")), strcmp("TOP", "TOP"));
	cr_assert_eq(strcmp("TOP", "TAP"), s(my_strcmp("TOP", "TAP")));
	cr_assert_eq(strcmp("TOP", "TOZ"), s(my_strcmp("TOP", "TOZ")));
	cr_assert_eq(strcmp("TAP", "TOP"), s(my_strcmp("TAP", "TOP")));
	cr_assert_eq(strcmp("TOZ", "TOP"), s(my_strcmp("TOZ", "TOP")));
	cr_assert_eq(s(my_strcmp("TO", "TOP")), strcmp("TO", "TOP"));
	cr_assert_eq(s(my_strcmp("", "TOP")), strcmp("", "TOP"));
}
