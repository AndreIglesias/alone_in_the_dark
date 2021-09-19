/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:03:53 by ciglesia          #+#    #+#             */
/*   Updated: 2021/09/19 18:40:45 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	sub_nums(char *n1, char *n2)
{
	int		neg;
	char	*big;
	int		bsize;
	char	*small;
	int		ssize;

	neg = 0;
	if (ft_strlen(n1) < ft_strlen(n2) - 1)
		neg = 1;
	else if ((ft_strlen(n1) == ft_strlen(n2) - 1) && ft_strcmp(n1, &n2[1]) < 0)
		neg = 1;
	//if neg, n2 > n1
	if (neg)
	{
		write(1, "-", 1);
		big = &n2[1];
		small = n1;
	}
	else
	{
		big = n1;
		small = &n2[1];
	}
	bsize = ft_strlen(big);
	ssize = ft_strlen(small);
	//big - small

	char	*result;
	int		tmp;
	int		res = 0;
	int		size = bsize;
	result = malloc(sizeof(char) * (size + 1));
	while (size > 0)
		result[--size] = 0;
	size = bsize;
	while (bsize)
	{
		bsize--;
		if (ssize > 0)
		{
			ssize--;
			tmp = ((big[bsize] - '0') - (small[ssize] - '0')) - res;
		}
		else
			tmp = (big[bsize] - '0') - res;
		res = 0;
		if (tmp < 0)
		{
			tmp += 10;
			res = 1;
		}
		result[bsize + 1] = tmp + '0';
	}
	int j = 0;
	while (j < size + 1 && !('0' <= result[j] && result[j] <= '9'))
		j++;
	while (j < size + 1 && result[j] == '0')
		j++;
	for (int i = j; i < size + 1; i++)
	{
		if ('0' <= result[i] && result[i] <= '9')
			write(1, &result[i], 1);
	}
	write(1, "\n", 1);
}

void	add_nums(char *n1, char *n2)
{
	char	*big;
	int		bsize;
	char	*small;
	int		ssize;

	big = n2;
	small = n1;

	bsize = ft_strlen(n2);
	ssize = ft_strlen(n1);

	if (bsize < ssize)
	{
		big = n1;
		small = n2;

		bsize = ft_strlen(n1);
		ssize = ft_strlen(n2);
	}

	char	*result;
	int		tmp;
	int		res = 0;
	int		size = bsize;
	result = malloc(sizeof(char) * (size + 1));
	while (size > 0)
		result[--size] = 0;
	size = bsize;
	while (bsize)
	{
		bsize--;
		if (big[bsize] == '-')
			break ;
		if (ssize > 0)
		{
			ssize--;
			if (small[ssize] != '-')
				tmp = ((big[bsize] - '0') + (small[ssize] - '0')) + res;
			else
				tmp = (big[bsize] - '0') + res;
		}
		else
			tmp = (big[bsize] - '0') + res;
		res = 0;
		if (tmp > 9)
		{
			tmp -= 10;
			res = 1;
		}
		result[bsize + 1] = tmp + '0';
	}
	if (big[0] == '-')
		write(1, "-", 1);
	for (int i = 0; i < size + 1; i++)
	{
		if ('0' <= result[i] && result[i] <= '9')
			write(1, &result[i], 1);
	}
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		if ((av[1][0] == '-' && av[2][0] == '-') ||
			(av[1][0] != '-' && av[2][0] != '-'))
			add_nums(av[1], av[2]);
		else
		{
			if (av[2][0] == '-')
				sub_nums(av[1], av[2]);
			else
				sub_nums(av[2], av[1]);
		}
	}
	else
		write(1, "\n", 1);
}
