/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:27:18 by ciglesia          #+#    #+#             */
/*   Updated: 2021/09/20 17:42:40 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		brackets(char *b)
{
	char	history[5000000] = {0};
	int		h = 0;

	for (int i = 0; b[i]; i++)
	{
		if (b[i] == '(' || b[i] == '[' || b[i] == '{')
			history[h++] = b[i];
		if (b[i] == ')' || b[i] == ']' || b[i] == '}')
		{
			if (!h)
				return (write(1, "Error\n", 6));
			if (b[i] == ')' && history[h - 1] != '(')
				return (write(1, "Error\n", 6));
			if (b[i] == '}' && history[h - 1] != '{')
				return (write(1, "Error\n", 6));
			if (b[i] == ']' && history[h - 1] != '[')
				return (write(1, "Error\n", 6));
			history[h - 1] = 0;
			h--;
		}
	}
	if (h)
		return (write(1, "Error\n", 6));
	return (write(1, "OK\n", 3));
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		for (int i = 1; i < ac; i++)
			brackets(av[i]);
	}
	else
		write(1, "\n", 1);
	return (0);
}
