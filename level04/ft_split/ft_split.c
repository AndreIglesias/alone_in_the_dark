/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:11:50 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/22 21:00:42 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		skip_separation(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	char	**spl;
	int		i;
	int		x;
	int		i_word;

	spl = (char **)malloc(sizeof(char *) * 100000);
	i = 0;
	x = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		{
			spl[x] = (char *)malloc(sizeof(char) * 100000);
			i_word = 0;
			while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
				spl[x][i_word++] = str[i++];
			spl[x][i_word] = 0;
			x++;
		}
		else
			i = skip_separation(str, i);
	}
	spl[x] = NULL;
	return (spl);
}

/* tests */

#include <stdio.h>

void	print_split(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		printf("[%s] ", spl[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		print_split(ft_split(av[i]));
	return (0);
}
