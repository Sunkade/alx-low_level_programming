#include "main.h"
/**
 * create_file - Creates a file.
 * @filename: is the name of the file to created
 * @text_content: is a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int wq;
int up;
int b;
if (!filename)
return (-1);
wq = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (wq == -1)
return (-1);
if (!text_content)
text_content = "";
for (up = 0; text_content[up];)
up++;
b = write(wq, text_content, up);
if (b == -1)
return (-1);
close(wq);
return (1);
}
