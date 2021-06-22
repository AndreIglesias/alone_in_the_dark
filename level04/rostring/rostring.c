/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:44:02 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/22 22:04:16 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

static int	skip_spaces(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

void	rostring(char *str)
{
	char	*first;
	int		printed;
	int		last_space;
	int		i;
	int		x;

	first = (char *)malloc(sizeof(char) * 100000);
	i = 0;
	x = 0;
	printed = 0;
	last_space = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			i = skip_spaces(str, i);
			if (printed)
				ft_putchar(' ');
		}
		else if (!printed)
		{
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				first[x++] = str[i++];
			first[x] = 0;
			i = skip_spaces(str, i);
			printed = 1;
		}
		else
		{
			last_space = 1;
			ft_putchar(str[i++]);
		}
	}
	if (last_space)
		ft_putchar(' ');
	ft_putstr(first);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
