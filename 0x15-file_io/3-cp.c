#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * error_file - checks if teh files can be opened
 * @file_from: file_from
 * @file_to:  already exists, truncate it
 * @argv: rep arguments vector
 * Return: no argument to return
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - to check for the number of people
 * @argc: the numberb of argument
 * @argv: the array of the number of argument
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t r, u;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, argv);

	r = 1024;
	while (r == 1024)
	{
		r = read(file_from, buf, 1024);
		if (r == -1)
			error_file(-1, 0, argv);
		u = write(file_to, buf, r);
		if (u == -1)
			error_file(0, -1, argv);
	}

	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
