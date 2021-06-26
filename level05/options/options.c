/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:43:31 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/26 18:39:41 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	97  - a
**	122 - z
*/

int	invalid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'a' || 'z' < str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_pow(int a, int b)
{
	int	res = 1;

	while (0 < b)
	{
		res *= a;
		b--;
	}
	return (res);
}


void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	add_letters(char *str, int result)
{
	int	i;

	i = 0;
	while (str[i])
	{
		result = result | ft_pow(2, (int)(str[i] - 'a'));
		i++;
	}
	return (result);
}

int	main(int ac, char **av)
{
	int	i;
	int	result;

	if (ac > 1)
	{
		result = 0;
		i = 1;
		while (i < ac)
		{
			if (av[i][1] && invalid(&av[i][1]))
			{
				write(1, "Invalid Option\n", 15);
				return (1);
			}
			else if (av[i][1] && av[i][1] == 'h')
			{
				write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
				return (0);
			}
			if (av[i][0] == '-')
				result = add_letters(&av[i][1], result);
			i++;
		}
		ft_putnbr(result);
		write(1, "\n", 1);
	}
	else
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	return (0);
}
