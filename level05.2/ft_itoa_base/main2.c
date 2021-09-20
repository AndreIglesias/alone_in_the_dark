/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:42:15 by ciglesia          #+#    #+#             */
/*   Updated: 2021/09/20 19:44:08 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
char    *ft_itoa_base(int value, int base);
int	main(void)
{
	int base;
	int test;

	base = 10;
	test = INT_MIN;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = -1;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = 0;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = 1;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = INT_MAX;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);

	base = 8;
	test = 28;
	printf("%s\n%o\n", ft_itoa_base(test, base), test);
	test = INT_MAX;
	printf("%s\n%o\n", ft_itoa_base(test, base), test);

	base = 16;
	test = 0xABCDEF9;
	printf("%s\n%x\n", ft_itoa_base(test, base), test);
	test = INT_MAX;
	printf("%s\n%x\n", ft_itoa_base(test, base), test);
	return (0);
}


/*
** tests
*/

/*
#include <stdio.h>
#include <limits.h>
int main(void)
{
	printf("%d: %s\n", INT_MIN, ft_itoa_base(INT_MIN, 10));
	printf("%x: %s\n", INT_MIN, ft_itoa_base(INT_MIN, 16));
	return (0);
}
*/
