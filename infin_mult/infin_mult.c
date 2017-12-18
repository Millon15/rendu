
#include "infin_mult.h"


#include <stdio.h>

int		printarr(char *buf, int k2)
{
	int		i;

	i = 0;
	while (buf[i] == '0' || buf[i] == '-')
		i++;
	if (!buf[i])
		return (write(1, "0\n", 2));
	if (k2)
		write(1, "-", 1);
	while (buf[i])
		write(1, &buf[i++], 1);
//	free(buf);
	return (write(1, "\n", 1));
}

char	*mult_by_one_digit(char *buf, char *av1, char *av2, int k[])
{
	int		len;
	int		rem;
	int		fn;
	int		j;

	len = k[0] - k[3] + 2;
	buf = (char *)malloc(sizeof(char) * len);
	buf[len--] = 0;
	j = k[0];
	rem = 0;
	while (len >= 0)
	{
		fn = (((j >= k[3] ? av1[j--] : '0') - '0') *
					(av2[k[1]] - '0') + rem + '0');
		if (fn > '9')
		{
			rem = (fn - '0') / 10;
			buf[len] = (fn - '0') % 10 + '0';
		}
		else if ((buf[len] = fn) <= '9')
			rem = 0;
		len--;
	}
	return (buf);
}

void	infin_mult(char **cop, char *av1, char *av2, int k[])
{
	int		len;
	int		rem;

	len = k[1] - k[4] + 1;
	cop = (char **)malloc(sizeof(char *) * len);

	rem = 0;
	printf("k is : ");
	while (rem < 5)
		printf("%d ", k[rem++]);
	rem = len;
	
	printf("\nlen is : %d\n", len);
	printf("av1 is : %s\n", av1);
	printf("av2 is : %s\n", av2);

	cop[len--] = NULL;
	while (k[1] >= k[4])
	{
		cop[len--] = mult_by_one_digit(cop[len], av1, av2, k);
		k[1]--;
	}

	printf("len is : %d\n", len);
	len = rem;
	rem = 0;
	while (rem <= len)
	{
		printf("cop[%d] is : %p\n", rem, cop[rem]);
		rem++;
	}

	printarr(cop[0], k[2]);

	rem = 0;
	while (rem < 20)
		printf("%d ", cop[0][rem++]);

}

int		main(int ac, char **av)
{
	int		k[5];
	int		i;

	if (ac != 3 || !av[1][0] || !av[2][0])
		return (write(1, "\n", 1));
	i = 0;
	while (i < 5)
		k[i++] = 0;
	if (av[1][0] == '-')
		k[3] = 1;
	if (av[2][0] == '-')
		k[4] = 1;	
	if (av[1][0] == '-' || av[2][0] == '-')
		k[2] = 1;
	if (av[1][0] == '-' && av[2][0] == '-')
		k[2] = 0;
	while (av[1][k[0] + 1])
		k[0]++;
	while (av[2][k[1] + 1])
		k[1]++;
	infin_mult(NULL, av[1], av[2], k);
	return (0);
}
