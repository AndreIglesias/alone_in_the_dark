/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:41:38 by ciglesia          #+#    #+#             */
/*   Updated: 2021/09/20 22:58:35 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	infin_mult(char *n1, char *n2)
{
	int	len1 = ft_strlen(n1);
	int	len2 = ft_strlen(n2);
	int	size = len1 + len2;
	int	result[size];

	if (n1[0] == '0' || n2[0] == '0')
		return (write(1, "0", 1));
	for (int i = 0; i < size; i++)
		result[i] = 0;

	for (int i = len1 - 1; i >= 0; i--)
		for (int j = len2 - 1; j >= 0; j--)
			result[i + j + 1] += (n1[i] - '0') * (n2[j] - '0');
	for (int i = size - 1; i > 0; i--)
	{
		result[i - 1] += result[i] / 10;
		result[i] %= 10;
	}
	int		i = 0;
	char	c;
	while (result[i] == 0)
		i++;
	for (; i < size; i++)
	{
		c = result[i] + '0';
		write(1, &c, 1);
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		if ((av[1][0] == '-' && av[2][0] == '-') ||
			(av[1][0] != '-' && av[2][0] != '-'))
		{
			if (av[1][0] == '-')
				infin_mult(&av[1][1], &av[2][1]);
			else
				infin_mult(av[1], av[2]);
		}
		else
		{
			if (av[1][0] == '-')
			{
				if (av[1][1] != '0' && av[2][0] != '0')
					write(1, "-", 1);
				infin_mult(&av[1][1], av[2]);
			}
			else
			{
				if (av[2][1] != '0' && av[1][0] != '0')
					write(1, "-", 1);
				infin_mult(av[1], &av[2][1]);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
