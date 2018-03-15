/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_memcpy.c
*/
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static void (*my_memcpy)(void *, void *, size_t) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_memcpy = dlsym(lib, "memcpy");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_memcpy = NULL;
}

Test(memcpy, test_each_char_equal, .init=setup, .fini=teardown)
{
	int size = 100;
	int *test1 = malloc(size * sizeof(int));
	int *test2 = malloc(size * sizeof(int));

	memset(test1, 1, sizeof(int) * size);
	my_memcpy(test2, test1, sizeof(int) * size);
	for (int i = 0; i < size * sizeof(int); i++) {
		cr_assert_eq(((char *)test1)[i], ((char *)test2)[i],
		"memcpy failed on %d: %d != %d", i, ((char *)test1)[i],
		((char *)test2)[i]);
	}
}
