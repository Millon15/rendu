
#include "infin_mult.h"

int		ft_strlen(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
		i++;
	return (i);
}

char	*adding(char *buf, char *av1, char *av2, int k[])
{
	int		len;
	int		rem;
	int		i;
	int		j;

	i = ft_strlen(av1);
	len = i-- + 3;
	buf = (char *)malloc(sizeof(char) * len);
	buf[len--] = '\0';
	buf[len--] = '\0';
	j = ft_strlen(av2) - 1;
	rem = 0;
	while (len >= 0)
		if ((buf[len--] = ((i >= 0 ? av1[i--] : '0') +
		(j >= 0 ? av2[j--] : '0') + (rem ? rem-- : 0) - '0')) > '9')
		{
			rem = 1;
			buf[len + 1] -= 10;
		}
	return (buf);
}
