#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int     fd;
	char 	*tmp;

	fd = 0;
	while (tmp)
	{
		tmp = get_next_line(fd);
		printf("%s", tmp);
	}
	return (0);
}
