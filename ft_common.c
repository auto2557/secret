#include <unistd.h>

// Prints a single char
void pchar(char c)
{
	write(1, &c, 1);
}

// Prints a string
void pstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

// Returns the length of a string
int slen(char *s)
{
	int len = 0;
	while (s[len])
		len++;
	return (len);
}

// Converts a string to an integer
int to_int(char *s)
{
	int i = 0;
	int n = 0;
	int neg = 0;

	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	while (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			neg++;
	while (s[i] >= '0' && s[i] <= '9')
		n = n * 10 + (s[i++] - '0');
	return (neg % 2 ? -n : n);
}

// Prints a number
void pnum(int n)
{
	unsigned int num;

	if (n < 0)
	{
		pchar('-');
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		pnum(num / 10);
	pchar(num % 10 + '0');
}
