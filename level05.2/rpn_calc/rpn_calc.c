/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:53:59 by ciglesia          #+#    #+#             */
/*   Updated: 2021/09/20 19:19:21 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define ISNUM(x) ('0' <= x && x <= '9')
#define ISOP(x) (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
#define ISDIV(x) (x == '/' || x == '%')

int		do_op(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
		return (a / b);
	if (op == '%')
		return (a % b);
	return (0);
}

int		rpn_calc(char *cmd)
{
	int	stack[500000] = {0};
	int	s = 0;
	int	i = 0;

	while (cmd[i])
	{
		if (ISNUM(cmd[i]) || cmd[i] == '-' && ISNUM(cmd[i + 1]))
		{
			stack[s++] = atoi(&cmd[i]);
			i += (cmd[i] == '-');
			for (; ISNUM(cmd[i]); i++);
		}
		else if (cmd[i] == ' ')
			for (; cmd[i] == ' '; i++);
		else if (ISOP(cmd[i]))
		{
			if (s < 2 || (ISDIV(cmd[i]) && stack[s - 1] == 0))
				return (write(1, "Error\n", 6));
			stack[s - 2] = do_op(stack[s - 2], stack[s - 1], cmd[i++]);
			stack[s - 1] = 0;
			s--;
		}
		else
			i++;
	}
	if (s == 1)
		printf("%d\n", stack[s - 1]);
	else
		printf("Error\n");
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rpn_calc(av[1]);
	else
		write(1, "Error\n", 6);
}
