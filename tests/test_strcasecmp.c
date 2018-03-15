/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_strcasecmp.c
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static int (*my_strcasecmp)(char *, char *) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_strcasecmp = dlsym(lib, "strcasecmp");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_strcasecmp = NULL;
}

Test(strcasecmp, match, .init = setup, .fini = teardown)
{
	cr_assert_eq(my_strcasecmp("TOP", "TOP"), strcasecmp("TOP", "TOP"));
	cr_assert_eq(my_strcasecmp("TOP", "TAP"), strcasecmp("TOP", "TAP"));
	cr_assert_eq(my_strcasecmp("TOP", "TOZ"), strcasecmp("TOP", "TOZ"));
	cr_assert_eq(my_strcasecmp("TAP", "TOP"), strcasecmp("TAP", "TOP"));
	cr_assert_eq(my_strcasecmp("TOZ", "TOP"), strcasecmp("TOZ", "TOP"));
	cr_assert_eq(my_strcasecmp("TOP", "top"), strcasecmp("TOP", "top"));
	cr_assert_eq(my_strcasecmp("TOP", "tap"), strcasecmp("TOP", "tap"));
	cr_assert_eq(my_strcasecmp("TOP", "toz"), strcasecmp("TOP", "toz"));
	cr_assert_eq(my_strcasecmp("top", "TOP"), strcasecmp("top", "TOP"));
	cr_assert_eq(my_strcasecmp("tap", "TOP"), strcasecmp("tap", "TOP"));
	cr_assert_eq(my_strcasecmp("toz", "TOP"), strcasecmp("toz", "TOP"));
	cr_assert_eq(my_strcasecmp("TOP1", "top"), strcasecmp("TOP1", "top"));
	cr_assert_eq(my_strcasecmp("TOP", "tap1"), strcasecmp("TOP", "tap1"));
	cr_assert_eq(my_strcasecmp("TOP1", "toz"), strcasecmp("TOP1", "toz"));
	cr_assert_eq(my_strcasecmp("tap", "TOP1"), strcasecmp("tap", "TOP1"));
	cr_assert_eq(my_strcasecmp("toz1", "TOP"), strcasecmp("toz1", "TOP"));
}