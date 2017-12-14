/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nr_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 01:02:47 by vbrazas           #+#    #+#             */
/*   Updated: 2017/12/15 01:13:45 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

int		main(int ac, char **av)
{
	int		fd;
	int		fd_to_write;
	ssize_t	ret;
	char	*buf;
	int		i;

	if (ac != 3 || (fd = open(av[1], O_RDONLY)) == -1)
		return (write(1, "\n", 1));
	fd_to_write = open(av[2], O_WRONLY);
	buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	i = 0;
	while (buf[i])
	{
		if (buf[i] == 10 || buf[i] == 13)
			buf[i] = '\n';
		i++;
	}
	write(fd_to_write, buf, ret);
	free(buf);
	close(fd);
	close(fd_to_open);
	return (0);
}
