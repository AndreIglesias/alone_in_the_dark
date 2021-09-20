/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:24:14 by ciglesia          #+#    #+#             */
/*   Updated: 2021/09/20 19:39:42 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_itoa_base(int value, int base)
{
	char			*l = "0123456789ABCDEF";
	unsigned int	num = value;
	int				i = 0;
	char			*res = malloc(10000000);

	if (2 <= base && base <= 16)
	{
		if (value < 0 && base == 10)
		{
			num = -value;
			res[i++] = '-';
		}
		if (value == 0)
			res[i++] = '0';
		while (num)
		{
			i++;
			num /= base;
		}
		num = value;
		if (value < 0 && base == 10)
			num = -value;
		res[i] = 0;
		while (num)
		{
			res[--i] = l[num % base];
			num /= base;
		}
		return (res);
	}
	return (NULL);
}

/*
** tests
*/
#include <stdio.h>
#include <limits.h>
int main(void)
{
	printf("%d: %s\n", INT_MIN, ft_itoa_base(INT_MIN, 10));
	printf("%x: %s\n", INT_MIN, ft_itoa_base(INT_MIN, 16));
	return (0);
}
