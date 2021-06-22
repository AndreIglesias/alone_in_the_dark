/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:39:05 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/22 19:50:44 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_intlen(long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	ft_abs(long nb)
{
	if (nb > 0)
		return (nb);
	return (-nb);
}

char	*ft_itoa(int nbr)
{
	long 	nb;
	int		len;
	char	*str;
	int		i;
	int		sign;

	nb = nbr;
	len = ft_intlen(nb);
	sign = 0;
	if (nb < 0)
		sign = 1;
	str = (char *)malloc(sizeof(char) * (len + sign + 1));
	i = len + sign;
	while (i > 0)
	{
		i--;
		str[i] = (char)(ft_abs(nb % 10) + '0');
		nb /= 10;
	}
	if (sign)
		str[0] = '-';
	str[len + sign] = 0;
	return (str);
}

/* tests */

#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_itoa(atoi(av[1])));
	return (0);
}
