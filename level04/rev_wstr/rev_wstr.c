/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:05:31 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/22 21:41:11 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


static int	word_size(char *str, int i)
{
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		i++;
	return (i);
}

static int	put_word(char *str, int i)
{
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		ft_putchar(str[i++]);
	return (i);
}

static int	skip_spaces(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

void	rev_wstr(char *str, int i)
{
	int	sp;

	if (str[i])
	{
		sp = 0;
		if (str[i] == ' ' || str[i] == '\t')
		{
			i = skip_spaces(str, i);
			sp = 1;
		}
		rev_wstr(str, word_size(str, i));
		put_word(str, i);
		if (sp)
			ft_putchar(' ');
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1], 0);
	write(1, "\n", 1);
	return (0);
}
