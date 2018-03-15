/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_strlen.c
*/
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static int (*my_strlen)(char const *) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_strlen = dlsym(lib, "strlen");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_strlen = NULL;
}

Test(strlen, len, .init = setup, .fini = teardown)
{
	char *str = "courge";

	cr_assert_eq(strlen(str), my_strlen(str));
	str = "ok";
	cr_assert_eq(strlen(str), my_strlen(str));
	str = "prout";
	cr_assert_eq(strlen(str), my_strlen(str));
	str = "   azaz aza  azaz ";
	cr_assert_eq(strlen(str), my_strlen(str));
	str = "qsdfghjklm";
	cr_assert_eq(strlen(str), my_strlen(str));
}
