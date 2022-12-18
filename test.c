#include "get_next_line.h"

int main()
{
	char *a;
	int fd = open("test.txt", O_RDONLY);
	int i = 0;

	while (i < 11)
	{
		a = get_next_line(fd);
		printf("%s\n", a);
		i++;
	}
	close(fd);
	return (0);
}