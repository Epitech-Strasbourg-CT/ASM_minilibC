/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test_strstr.c
*/
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <criterion/criterion.h>

static void *lib = NULL;
static int (*my_write)(int fd, void *ptr, size_t size) = NULL;
static int (*my_read)(int fd, void *ptr, size_t size) = NULL;

static void setup(void)
{
	lib = dlopen("./libasm.so", RTLD_LAZY);
	my_write = dlsym(lib, "write");
	my_read = dlsym(lib, "read");
}

static void teardown(void)
{
	dlclose(lib);
	lib = NULL;
	my_write = NULL;
	my_read = NULL;
}

Test(write, write1, .init = setup, .fini = teardown)
{
	char *str = "AZERTYUIOP\n";
	int fd = 1;
	size_t len = strlen(str);

	int a = write(fd, str, len);
	int b = my_write(fd, str, len);
	cr_assert_eq(a, b, "%d != %d\n %s\n", a, b, strerror(errno));
}

Test(write, write_error, .init = setup, .fini = teardown)
{
	char *str = "AZERTYUIOP\n";
	int fd = 0;
	size_t len = strlen(str);

	int a = write(fd, str, len);
	int errno_a = errno;
	int b = my_write(fd, str, len);
	int errno_b = errno;
	cr_assert_eq(a, b, "write diff %d != %d\n\n", a, b);
	cr_assert_eq(errno_a, errno_b, "errno diff\n");
}


Test(read, read1, .init = setup, .fini = teardown)
{
	char str1[10];
	char str2[10];
	int fd1[2];
	int fd2[2];

	pipe(fd1);
	pipe(fd2);
	write(fd1[1], "azertyuio", 10);
	write(fd2[1], "azertyuio", 10);
	int a = read(fd1[0], str1, 10);
	int b = my_read(fd2[0], str2, 10);
	cr_assert_eq(a, b, "read diff %d != %d\n\n", a, b);
	cr_assert_eq(strcmp(str1, str2), 0, "read dif %s %sf\n", str1, str2);
}

Test(read, read_error, .init = setup, .fini = teardown)
{
	char str[10];
	int fd = -1;
	size_t len = strlen(str);

	int a = read(fd, str, len);
	int errno_a = errno;
	int b = my_read(fd, str, len);
	int errno_b = errno;
	cr_assert_eq(a, b, "write diff %d != %d\n\n", a, b);
	cr_assert_eq(errno_a, errno_b, "errno diff\n");
}