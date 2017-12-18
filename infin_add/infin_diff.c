
#include "infin_add.h"

int		printarr(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] == '0' || buf[i] == '-')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (write(1, "0\n", 2));
	}
	if (buf[0] == '-')
		write(1, "-", 1);
	while (buf[i])
		write(1, &(buf[i++]), 1);
	write(1, "\n", 1);
	free(buf);
	return (0);
}

void	if_swap(char **av1, char **av2, int k[])
{
	char	*b;
	int		i;

	if ((*av1)[0] == '-')
	{
		b = *av1;
		*av1 = *av2;
		*av2 = b;
		i = k[2];
		k[2] = k[3];
		k[3] = i;
		i = k[0];
		k[0] = k[1];
		k[1] = i;
	}
}

int		sum(char **av1, char **av2, int k[])
{
	int		i;
	int		s1;
	int		s2;

	i = k[0];
	s1 = 0;
	while ((*av1)[i])
		s1 = s1 + (*av1)[i++];
	i = k[1];
	s2 = 0;
	while ((*av2)[i])
		s2 = s2 + (*av2)[i++];
	if (s1 == s2)
		return (2);
	if ((s1 - s2) < 0)
	{
		if_swap(av2, av1, k);
		return (k[4] = 1);
	}
	return (0);
}

int		infin_diff(char *buf, char *av1, char *av2, int k[])
{
	int		rem;
	int		len;

	if_swap(&av1, &av2, k);
	k[4] = 0;
	if ((rem = sum(&av1, &av2, k)) == 2)
		return (write(1, "0\n", 2));
	len = (k[2] > k[3] ? k[2] : k[3]) + 2;
	buf = (char *)malloc(sizeof(char) * len);
	buf[len--] = '\0';
	rem = 0;
	while (len >= 1)
		if (((buf[len--] = (k[2] >= k[0] ? av1[k[2]--] : '0') -
				(k[3] >= k[1] ? av2[k[3]--] : '0') -
				(rem == 0 ? rem : rem--) + '0') < '0') &&
				(rem = 1))
			buf[len + 1] += 10;
	if (k[4])
		buf[len] = '-';
	else
		buf[len] = '0';
	return (printarr(buf));
}
