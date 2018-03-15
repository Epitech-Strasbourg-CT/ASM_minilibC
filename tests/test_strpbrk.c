/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_strpbrk.c
*/
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static char *(*my_strpbrk)(const char *s, const char *accept) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_strpbrk = dlsym(lib, "strpbrk");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_strpbrk = NULL;
}

Test(strpbrk, strpbrk1, .init = setup, .fini = teardown)
{
	char *str;
	char *accept;
	char *b = 0;
	char *a = 0;

	str = "AZERTYUIOP";
	accept = "POIUYTREZA";
	b = strpbrk(str, accept);
	a = my_strpbrk(str, accept);
	cr_assert_eq(a, b);
}

Test(strpbrk, strpbrk2, .init = setup, .fini = teardown)
{
	char *str;
	char *accept;
	char *b = 0;
	char *a = 0;

	str = "AZERTYUIOP";
	accept = "";
	b = strpbrk(str, accept);
	a = my_strpbrk(str, accept);
	cr_assert_eq(a, b);
}

Test(strpbrk, strpbrk3, .init = setup, .fini = teardown)
{
	char *str;
	char *accept;
	char *b = 0;
	char *a = 0;


	str = "AZERTYUIOP";
	accept = "QSDFGHJKLM";
	b = strpbrk(str, accept);
	a = my_strpbrk(str, accept);
	cr_assert_eq(a, b);
}

Test(strpbrk, strpbrk4, .init = setup, .fini = teardown)
{
	char *str;
	char *accept;
	char *b = 0;
	char *a = 0;


	str = 0;
	accept = "";
	b = strpbrk(str, accept);
	a = my_strpbrk(str, accept);
	cr_assert_eq(a, b);
}