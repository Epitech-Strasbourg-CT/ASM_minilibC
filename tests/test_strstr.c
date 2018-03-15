/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_strstr.c
*/
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static char *my_strstr(const char *haystack, const char *needle) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_strchr = dlsym(lib, "strchr");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_strchr = NULL;
}

Test(strstr, strstr1, .init = setup, .fini = teardown)
{
	char *test = "AZERTYUIOP";
	char *a = 0;
	char *b = 0;

	a = my_strstr(test, "FGHJ");
	b = strstr(test, "FGHJ");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}
}

Test(strstr, strstr2, .init = setup, .fini = teardown)
{
	char *test = "AZERTYUIOP";
	char *a = 0;
	char *b = 0;

	a = my_strstr(test, "AZER");
	b = strstr(test, "AZER");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}
}

Test(strstr, strstr3, .init = setup, .fini = teardown)
{
	char *test = "AZERTYUIOP";
	char *a = 0;
	char *b = 0;

	a = my_strstr(test, " ");
	b = strstr(test, " ");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}
}

Test(strstr, strstr4, .init = setup, .fini = teardown)
{
	char *test = "AZERTYUIOP";
	char *a = 0;
	char *b = 0;

	test = "AZERTYUIOP";
	a = my_strstr(test, "UIOP");
	b = strstr(test, "UIOP");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}
}

Test(strstr, strstr5, .init = setup, .fini = teardown)
{
	char *test = "AZERTYUIOP";
	char *a = 0;
	char *b = 0;

	test = "AZERTYUIOP";
	a = my_strstr(test, "UIOP1");
	b = strstr(test, "UIOP1");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}
}

Test(strstr, strstr6, .init = setup, .fini = teardown)
{
	char *test = "AZERTYUIOP";
	char *a = 0;
	char *b = 0;

	test = "AZERTYUIOP";
	a = my_strstr(test, "");
	b = strstr(test, "");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}
}
