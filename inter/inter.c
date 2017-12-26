/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 09:21:44 by vbrazas           #+#    #+#             */
/*   Updated: 2017/12/26 09:21:48 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char a[], int b[])
{
	int		i;

	i = 0;
	while (a[i])
	{
		if (b[i])
			write(1, &(a[i]), 1);
		i++;
	}
	write(1, "\n", 1);
}

void	compare(char *av2, char a[], int b[])
{
	int		i;
	int		j;

	i = 0;
	while (a[i])
	{
		j = 0;
		while (av2[j] && a[i] != av2[j])
			j++;
		if (av2[j])
			b[i] = 1;
		i++;
	}
}

void	write_a(char *av1, char a[])
{
	int		i;
	int		j;

	i = 0;
	while (av1[i])
	{
		j = 0;
		while (a[j] && av1[i] != a[j])
			j++;
		if (!a[j])
		{
			j = 0;
			while (a[j])
				j++;
			a[j] = av1[i];
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	char	a[27];
	int		b[27];
	int		i;

	if (ac != 3)
		return (write(1, "\n", 1));
	i = 0;
	while (i < 27)
	{
		a[i] = 0;
		b[i] = 0;
		i++;
	}
	write_a(av[1], a);
	compare(av[2], a, b);
	print(a, b);
	return (0);
}
