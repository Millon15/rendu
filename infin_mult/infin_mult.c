/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:45:24 by vbrazas           #+#    #+#             */
/*   Updated: 2017/12/26 09:21:22 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

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
	free(buf);
	return (write(1, "\n", 1));
}

void	help_for_mbod(char **buf, int *len, int k[])
{
	int		nulls;

	nulls = k[5]++;
	*len = k[0] - k[3] + nulls + 3;
	*buf = (char *)malloc(sizeof(char) * (*len));
	(*buf)[(*len)--] = '\0';
	(*buf)[(*len)--] = '\0';
	while (nulls--)
		(*buf)[(*len)--] = '0';
}

char	*mult_by_one_digit(char *buf, char *av1, char *av2, int k[])
{
	int		len;
	int		rem;
	int		fn;
	int		j;

	help_for_mbod(&buf, &len, k);
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

int		infin_mult(char *cop, char *av1, char *av2, int k[])
{
	char	*bbb;

	bbb = mult_by_one_digit(NULL, av1, av2, k);
	k[1]--;
	while (k[1] >= k[4])
	{
		cop = mult_by_one_digit(NULL, av1, av2, k);
		bbb = adding(NULL, bbb, cop, k);
		free(cop);
		k[1]--;
	}
	return (printarr(bbb, k[2]));
}

int		main(int ac, char **av)
{
	int		k[6];
	int		i;

	if (ac != 3 || !av[1][0] || !av[2][0])
		return (write(1, "\n", 1));
	i = 0;
	while (i < 6)
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
