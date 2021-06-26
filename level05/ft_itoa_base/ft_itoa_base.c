/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:54:12 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/26 21:19:28 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_itoa_base(int value, int base)
{
	char			*lexicon = "0123456789ABCDEF";
	char			*ret;
	unsigned int	n;
	int				i;

	if (2 <= base && base <= 16)
	{
		ret = (char *)malloc(400000);
		n = value;
		i = 0;
		if (base == 10 && value < 0)
		{
			n = -value;
			ret[i++] = '-';
		}
		if (value == 0)
			ret[i++] = '0';
		while (n)
		{
			i++;
			n /= base;
		}
		ret[i] = 0;
		n = value;
		if (base == 10 && value < 0)
			n = -value;
		while (n)
		{
			i--;
			ret[i] = lexicon[n % base];
			n /= base;
		}
		return (ret);
	}
	return (NULL);
}

/* tests */

#include <stdio.h>

int main(int ac, char **av)
{
	for (int i = 1; i + 1 < ac; i += 2)
		printf("itoabase: %d in base %d = %s\n",
			   atoi(av[i]), atoi(av[i + 1]), ft_itoa_base(atoi(av[i]), atoi(av[i + 1])));
	return (0);
}
