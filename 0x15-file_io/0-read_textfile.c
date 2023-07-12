#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file and prinits.
 * @filename: is the number of letters it should read and print
 * @letters: returns the actual number
 *
 * Return: numbers of letters printed. it fails, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int wq;
	ssize_t r;
	ssize_t q;
	char *buf;

	if (!filename)
		return (0);

	wq = open(filename, O_RDONLY);

	if (wq == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	r = read(wq, buf, letters);
	q = write(STDOUT_FILENO, buf, r);

	close(wq);

	free(buf);

	return (q);
}
