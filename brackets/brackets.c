
#include <unistd.h>

int		check(int a[], int j, int max_j)
{
	int		l;

	if (j < 0)
		return (0);
	l = 0;
	a[max_j] = 5;
	while (a[l] == 0 && l <= max_j)
		l++;
	if (l == max_j)
		return (1);
	return (0);
}

int		brackets(char *avi, int i, int j, int max_j)
{
	int		a[200];

	while (avi[i] && j >= 0)
	{
		if (avi[i] == '(')
			a[j++] = 1;
		if (avi[i] == '[')
			a[j++] = 2;
		if (avi[i] == '{')
			a[j++] = 3;
		if (max_j < j)
			max_j = j;
		if (avi[i] == ')' && j)
			a[--j] -= 1;
		if (avi[i] == ']' && j)
			a[--j] -= 2;
		if (avi[i] == '}' && j)
			a[--j] -= 3;
		if ((avi[j] == ')' || avi[j] == ']' || avi[j] == '}') && !j)
			return (0);
		i++;
	}
	return ((check(a, j, max_j) ? 1 : 0));
}

int		main(int ac, char **av)
{
	int		i;

	if (ac < 2)
		return (write(1, "\n", 1));
	i = 1;
	while (i < ac)
	{
		if (brackets(av[i], 0, 0, 0))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}
