/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 05:22:32 by vbrazas           #+#    #+#             */
/*   Updated: 2017/12/15 06:33:57 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_itoa_base(int value, int base);

int		main()
{
	printf("%s\n", ft_itoa_base(123, 10));
	printf("%s\n", ft_itoa_base(-123, 10));
	printf("%s\n", ft_itoa_base(0, 10));
	printf("%s\n", ft_itoa_base(3, 8));
	printf("%s\n", ft_itoa_base(12, 8));
	printf("%s\n", ft_itoa_base(15, 16));
	printf("%s\n", ft_itoa_base(2, 2));
	printf("%s\n", ft_itoa_base(+2147483647, 10));
	printf("%s\n", ft_itoa_base(-2147483648, 10));
	printf("%s\n", ft_itoa_base(+2147483647, 2));
	printf("%s\n", ft_itoa_base(-2147483648, 2));
	return (0);
}
