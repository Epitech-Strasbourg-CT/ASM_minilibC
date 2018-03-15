/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_memmove.c
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static void (*my_memmove)(void *, void *, size_t) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_memmove = dlsym(lib, "memmove");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_memmove = NULL;
}

Test(memmove, right_not_overlap, .init = setup, .fini = teardown)
{
	char data1[50];
	char data2[50];
	size_t size = 50;

	memset(data1, 0, size);
	memset(data2, 0, size);
	memset(data1, 1, 20);
	memset(data2, 1, 20);
	memmove(data1, data1 + 30, 19);
	my_memmove(data2, data2 + 30, 19);
	for (int i = 0; i < size; i++) {
		cr_assert_eq(((char *)data1)[i], ((char *)data2)[i],
		"memmove failed on %d: %d != %d", i, ((char *)data1)[i],
		((char *)data2)[i]);
	}
}

Test(memmove, left_overlap, .init = setup, .fini = teardown)
{
	char data1[50];
	char data2[50];
	size_t size = 50;

	memset(data1, 0, size);
	memset(data2, 0, size);
	memset(data1, 1, 25);
	memset(data2, 1, 25);
	memmove(data1 + 25, data1 + 15, 25);
	my_memmove(data2 + 25, data2 + 15, 25);
	for (int i = 0; i < size; i++) {
		cr_assert_eq(((char *)data1)[i], ((char *)data2)[i],
		"memmove failed on %d: %d != %d", i, ((char *)data1)[i],
		((char *)data2)[i]);
	}
}

Test(memmove, right_overlap, .init = setup, .fini = teardown)
{
	char data1[50];
	char data2[50];
	size_t size = 50;

	memset(data1, 0, size);
	memset(data2, 0, size);
	memset(data1, 1, 25);
	memset(data2, 1, 25);
	memmove(data1 + 15, data1 + 25, 25);
	my_memmove(data2 + 15, data2 + 25, 25);
	for (int i = 0; i < size; i++) {
		cr_assert_eq(((char *)data1)[i], ((char *)data2)[i],
		"memmove failed on %d: %d != %d", i, ((char *)data1)[i],
		((char *)data2)[i]);
	}
}
