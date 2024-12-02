#include "functions.h"
#include <stdlib.h>

int chk(int ac, char **av)
{
	if (ac != 2 || slen(av[1]) != 31)
		return (1);
	return (0);
}

int *get_nums(char *s)
{
	int i = -1;
	int j = 0;
	int *arr;

	if (!(arr = malloc(sizeof(int) * 16)))
		return (0);
	while (s[++i])
		if (s[i] >= '0' && s[i] <= '9')
			arr[j++] = to_int(s + i);
	return (arr);
}
