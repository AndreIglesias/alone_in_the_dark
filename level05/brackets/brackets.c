/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:13:37 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/23 14:08:06 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	actual(char *str)
{
	int	i;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i + 1])
		i++;
	return (str[i]);
}

void	put_actual(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	str[i + 1] = 0;
}

void	pop_actual(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	str[i] = 0;
}

void	brackets(char *str)
{
	int		p;// ()
	int		s;// []
	int		b;// {}
	char	history[100000];
	int		i;

	i = 0;
	history[0] = 0;
	p = 0;
	s = 0;
	b = 0;
	while (str[i])
	{
		p += str[i] == '(';
		s += str[i] == '[';
		b += str[i] == '{';

		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			put_actual(history, str[i]);

		b -= (str[i] == '}' && actual(history) == '{');
		s -= (str[i] == ']' && actual(history) == '[');
		p -= (str[i] == ')' && actual(history) == '(');

		if ((str[i] == '}' && actual(history) == '{') ||
			(str[i] == ']' && actual(history) == '[') ||
			(str[i] == ')' && actual(history) == '('))
			pop_actual(history);
		else if (str[i] == '}' ||str[i] == ']' || str[i] == ')')
		{
			write(1, "Error\n", 6);
			return ;
		}

		i++;
	}
	if (!p && !s && !b)
		write(1, "OK\n", 3);
	else
		write(1, "Error\n", 6);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		write(1, "\n", 1);
	i = 1;
	while (i < ac)
		brackets(av[i++]);
	return (0);
}
