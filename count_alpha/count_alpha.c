/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:40:19 by vbrazas           #+#    #+#             */
/*   Updated: 2017/12/15 17:47:07 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	printarr(int b[], char m[])
{
	int		l;

	l = 0;
	while (m[l])
	{
		printf("%d%c", b[m[l] - 'a'], m[l]);
		if (m[l + 1])
			printf(", ");
		else
			printf("\n");
		l++;
	}
}

void	puttom(char m[], char *av, int i)
{
	int		l;

	l = 0;
	while (l < 26)
		if (av[i] == m[l++])
			return ;
	l = 0;
	while (l < 26 && m[l])
		l++;
	m[l] = av[i];
}

void	to_lower(char *buf)
{
	int		i;

	while (buf[i])
	{
		if (buf[i] >= 'A' && buf[i] <= 'Z')
			buf[i] += 32;
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		b[27];
	char	m[27];

	if (ac != 2)
		return (write(1, "\n", 1));
	to_lower(av[1]);
	i = 0;
	while (i < 27)
	{
		m[i] = 0;
		b[i++] = 0;
	}
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
		{
			puttom(m, av[1], i);
			(b[av[1][i] - 'a'])++;
		}
		i++;
	}
	printarr(b, m);
	return (0);
}
