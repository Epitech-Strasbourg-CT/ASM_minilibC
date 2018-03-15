/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_strcspn.c
*/
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static size_t (*my_strcspn)(const char *s, const char *reject) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_strcspn = dlsym(lib, "strcspn");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_strcspn = NULL;
}

Test(strcspn, accept_full, .init = setup, .fini = teardown)
{
	char *str;
	char *accept;
	size_t b = 0;
	size_t a = 0;

	str = "AZERTYUIOP";
	accept = "POIUYTREZA";
	b = strcspn(str, accept);
	a = my_strcspn(str, accept);
	cr_assert_eq(a, b);
}

Test(strcspn, accept_last, .init = setup, .fini = teardown)
{
	char *str;
	char *accept;
	size_t b = 0;
	size_t a = 0;

	str = "AZERTYUIOP";
	accept = "P";
	b = strcspn(str, accept);
	a = my_strcspn(str, accept);
	cr_assert_eq(a, b);
}

Test(strcspn, search_empty, .init = setup, .fini = teardown)
{
	char *str;
	char *accept;
	size_t b = 0;
	size_t a = 0;

	str = "AZERTYUIOP";
	accept = "";
	b = strcspn(str, accept);
	a = my_strcspn(str, accept);
	cr_assert_eq(a, b);
}

Test(strcspn, accept_not_in, .init = setup, .fini = teardown)
{
	char *str;
	char *accept;
	size_t b = 0;
	size_t a = 0;

	str = "AZERTYUIOP";
	accept = "QSDFGHJKLM";
	b = strcspn(str, accept);
	a = my_strcspn(str, accept);
	cr_assert_eq(a, b);
}
