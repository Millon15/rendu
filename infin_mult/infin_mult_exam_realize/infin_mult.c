/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:50:23 by exam              #+#    #+#             */
/*   Updated: 2018/01/19 17:34:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

int		print_number(char *res, int k[])
{
	int		i;

	i = 0;
	while (res[i] && res[i] == '0')
		i++;
	if (!res[i])
		return (write(1, "0\n", 2));
	if (k[0])
		write(1, "-", 1);
	while (res[i])
		write(1, &res[i++], 1);
	write(1, "\n", 1);
	return (0);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*infin_add(char *s1, char *s2, int i, int j)
{
	char	*ru;
	int		l;
	int		fr;
	int		rem;

	l = (i >= j ? (i) : (j)) + 1;
	ru = (char *)malloc(sizeof(char) * (l + 1));
	ru[l] = '\0';
	rem = 0;
	while (l-- > 0)
	{
		fr = (--i >= 0 ? (s1[i] - '0') : (0)) +\
				(--j >= 0 ? (s2[j] - '0') : (0)) + '0' + rem;
		rem = 0;
		if (fr > '9')
		{
			rem = (fr - '0') / 10;
			fr = (fr - '0') % 10 + '0';
		}
		ru[l] = (char)fr;
	}
	ru[l] = rem + '0';
	return (ru);
}

char	*mult_by_one_digit(char *av1, char d, int k[], char *res)
{
	char	*r;
	int		fr;
	int		rem;
	int		i;
	int		l;

	rem = 0;
	i = k[1] + k[5]++ - k[3] + 1;
	r = (char *)malloc(sizeof(char) * (i + 1));
	r[i] = '\0';
	l = k[5] - k[3] - 1;
	while (l--)
		r[--i] = '0';
	l = k[1];
	while (i-- > 0)
	{
		fr = (((--l - k[3]) >= 0 ? (av1[l] - '0') : (0)) * d + '0' + rem);
		rem = 0;
		if (fr > '9' && (rem = (fr - '0') / 10))
			fr = (fr - '0') % 10 + '0';
		r[i] = (char)fr;
	}
	return ((res ? infin_add(r, res, ft_strlen(r), ft_strlen(res)) : r));
}

/*
**k[0] - is '-' in both, or is not '-' in both, or '-' is in one of digits
**k[1] - lenth of av[1] array
**k[2] - lenth of av[2] array
**k[3] - if '-' is in av[1] then k[3] = 1, if isn't k[3] = 0
**k[4] - if '-' is in av[2] then k[4] = 1, if isn't k[4] = 0
**k[5] - indicator of present "sort" of 1st digit
*/

int		main(int ac, char **av)
{
	char	*res;
	int		k[6];

	if (ac != 3)
		return (write(1, "\n", 1));
	k[3] = (av[1][0] == '-') ? (1) : (0);
	k[4] = (av[2][0] == '-') ? (1) : (0);
	k[0] = (k[3] == k[4]) ? (0) : (1);
	k[1] = ft_strlen(av[1]);
	k[2] = ft_strlen(av[2]);
	k[5] = k[3];
	res = NULL;
	res = mult_by_one_digit(av[1], av[2][--k[2]] - '0', k, res);
	while (--k[2] >= k[4])
		res = mult_by_one_digit(av[1], av[2][k[2]] - '0', k, res);
	print_number(res, k);
	return (0);
}
