#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file
 * @filename: is the file name
 * @text_content: terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int e, r, wq = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
for (wq = 0; text_content[wq];)
wq++;
}

e = open(filename, O_WRONLY | O_APPEND);
r = write(e, text_content, wq);

if (r == -1 || e == -1)

return (-1);

close (e);
return (1);
}
