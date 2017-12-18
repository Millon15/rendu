/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:18:39 by vbrazas           #+#    #+#             */
/*   Updated: 2017/12/16 23:06:10 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

void	infin_add(char *buf, char *av1, char *av2, int k[])
{
	int		rem;
	int		len;

	len = (k[2] > k[3] ? k[2] : k[3]) + 2;
	buf = (char *)malloc(sizeof(char) * len);
	buf[len--] = '\0';
	rem = 0;
	while (len >= k[4])
	{
		if ((buf[len--] =
				(k[2] >= k[4] ? av1[k[2]--] : '0') +
				(k[3] >= k[4] ? av2[k[3]--] : '0') +
				(rem == 0 ? rem : rem--) - '0') > '9')
		{
			rem = 1;
			buf[len + 1] -= 10;
		}
	}
	if (k[4])
		buf[len] = '-';
	printarr(buf);
}

int		main(int ac, char **av)
{
	int		i;
	int		k[5];

	if (ac != 3 || !av[1][0] || !av[2][0])
		return (write(1, "\n", 1));
	i = 0;
	while (i < 5)
		k[i++] = 0;
	if (av[1][0] == '-')
		k[0] = 1;
	if (av[2][0] == '-')
		k[1] = 1;
	if ((av[1][0] == '-') || (av[2][0] == '-'))
		k[4] = 1;
	while (av[1][k[2] + 1])
		k[2]++;
	while (av[2][k[3] + 1])
		k[3]++;
	k[0] == k[1] ? infin_add(NULL, av[1], av[2], k) :
					infin_diff(NULL, av[1], av[2], k);
	return (0);
}
