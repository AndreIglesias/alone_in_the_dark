/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:47:37 by ciglesia          #+#    #+#             */
/*   Updated: 2021/09/20 18:12:15 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		valid_op(char *str)
{
	int i = 0;

	while (str[i] && ('a' <= str[i] && str[i] <= 'z'))
		i++;
	if (str[i])
		return (0);
	return (1);
}

int		calc_options(char *str)
{
	int x = 0;

	for (int i = 0; str[i]; i++)
		x |= (1 << (str[i] - 'a'));
	return (x);
}

void	ft_putnbr(int x)
{
	char c;

	c = x % 10 + '0';
	if (x > 9)
		ft_putnbr(x / 10);
	write (1, &c, 1);
}

int		options(char **op, int ac)
{
	int	x = 0;

	for (int i = 0; i < ac; i++)
		if (op[i][0] == '-' && !valid_op(&op[i][1]))
			return (write(1, "Invalid Option\n", 15));
	for (int i = 0; i < ac; i++)
	{
		if (op[i][0] == '-')
			x |= calc_options(&op[i][1]);
	}
	ft_putnbr(x);
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac == 1)
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	else
	{
		int	help = 0;
		for (int i = 1; i < ac; i++)
			if (av[i][0] == '-' && av[i][1] == 'h')
				help = 1;
		if (help)
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		else
			options(&av[1], ac - 1);
	}
	return (0);
}
