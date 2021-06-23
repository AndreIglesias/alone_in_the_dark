/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:07:09 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/23 19:40:11 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	brainfuck(char *code)
{
	char	ram[2049] = { [0 ... 2048] = 0};
	int		i = 0;
	int		ptr = 0;
	int		brackets;

	while (code[i])
	{
		brackets = 1;
		if (code[i] == '>')
			ptr++;
		else if (code[i] == '<')
			ptr--;
		else if (code[i] == '+')
			ram[ptr]++;
		else if (code[i] == '-')
			ram[ptr]--;
		else if (code[i] == '.')
			ft_putchar(ram[ptr]);
		else if (code[i] == '[' && ram[ptr] == 0)
		{
			while (code[i] && i <= 4096)
			{
				i++;
				if (code[i] == '[')
					brackets++;
				if (code[i] == ']' && brackets)
					brackets--;
				if (!brackets)
					break ;
			}
		}
		else if (code[i] == ']' && ram[ptr] != 0)
		{
			while (i >= 0)
			{
				i--;
				if (code[i] == ']')
					brackets++;
				if (code[i] == '[' && brackets)
					brackets--;
				if (!brackets)
					break ;
			}
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
