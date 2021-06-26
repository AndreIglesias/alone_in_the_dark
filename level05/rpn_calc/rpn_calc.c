/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 22:24:24 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/27 01:23:48 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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

void	evaluate(char *eq)
{
	int		stack[400000];
	char	*op = "+-*/%";
	int		p;
	int		i;

	i = 0;
	p = -1;
	while (eq[i])
	{
		if ('0' <= eq[i] && eq[i] <= '9' ||
		(eq[i] == '-' && '0' <= eq[i + 1] && eq[i + 1] <= '9'))
		{
			stack[++p] = atoi(&eq[i]);
			i += eq[i] == '-';
			while (eq[i] && ('0' <= eq[i] && eq[i] <= '9'))
				i++;
		}
		else if (eq[i] == ' ')
		{
			while (eq[i] == ' ')
				i++;
		}
		else if (find_char(op, eq[i]))
		{
			if (p < 1 || ((eq[i] == '/' || eq[i] == '%') && stack[p] == 0))
			{
				printf("Error\n");
				return ;
			}
			else
			{
				stack[p - 1] = do_op(stack[p - 1], stack[p], eq[i]);
				p--;
				i++;
			}
		}
		else
			i++;
	}
	if (p == 0)
		printf("%d\n", stack[0]);
	else
		printf("Error\n");
}

int main(int ac, char **av)
{
	if (ac == 2)
		evaluate(av[1]);
	else
		printf("Error\n");
	return (0);
}
