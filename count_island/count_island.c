/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:40:40 by vbrazas           #+#    #+#             */
/*   Updated: 2017/12/15 01:14:24 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

int		proper(char *buf, int i)
{
	while (buf[i] != '\n')
		i++;
	if (!buf[++i])
		return (0);
	return (1);
}

void	fill_island(char *buf, int i, int line, int nbr)
{
	int		l;

	l = i + 1;
	while (buf[l] && buf[l] == 'X')
		buf[l++] = nbr + '0';
	l = i;
	while (l >= 0 && buf[l] == 'X')
		buf[l--] = nbr + '0';
	l = i;
	while (l >= 0 && buf[l] == (nbr + '0'))
	{
		if (proper(buf, l) && buf[l + line + 1] == 'X')
			fill_island(buf, l + line + 1, line, nbr);
		if (l > line && buf[l - line - 1] == 'X')
			fill_island(buf, l - line - 1, line, nbr);
		l--;
	}
	while (buf[i] == (nbr + '0'))
	{
		if (proper(buf, i) && buf[i + line + 1] == 'X')
			fill_island(buf, i + line + 1, line, nbr);
		if (i > line && buf[i - line - 1] == 'X')
			fill_island(buf, i - line - 1, line, nbr);
		i++;
	}
}

int		algo(char *buf, int line)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (buf[i])
	{
		if (buf[i] == 'X')
		{
			fill_island(buf, i, line, nbr);
			if (++nbr > 10)
				return (1);
		}
		i++;
	}
	return (0);
}

int		validator(char *buf, int *line)
{
	int		i;

	i = 0;
	*line = 0;
	while (buf[(*line)] != '\n')
		(*line)++;
	while (buf[i])
	{
		if (buf[i] != '.' && buf[i] != 'X' && buf[i] != '\n')
			return (1);
		if (buf[i] == '\n')
			if ((i - (*line)) % ((*line) + 1))
				return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	ssize_t	ret;
	int		line;
	char	*buf;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1)
		return (write(1, "\n", 1));
	if (!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (write(1, "\n", 1));
	if (!(ret = read(fd, buf, BUF_SIZE)) || ret == -1)
		return (write(1, "\n", 1));
	buf[ret] = '\0';
	if (validator(buf, &line) || algo(buf, line))
	{
		free(buf);
		return (write(1, "\n", 1));
	}
	write(1, buf, ret);
	free(buf);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
