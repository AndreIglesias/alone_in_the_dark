/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:22:37 by ciglesia          #+#    #+#             */
/*   Updated: 2021/09/18 15:05:42 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	replace_by(char map[1024][1024], char num, int i, int j)
{
	if (map[j][i] == 'X')
	{
		map[j][i] = num;
		if (map[j + 1][i] == 'X')
			replace_by(map, num, i, j + 1);
		if (map[j - 1][i] == 'X')
			replace_by(map, num, i, j - 1);
		if (map[j][i + 1] == 'X')
			replace_by(map, num, i + 1, j);
		if (map[j][i - 1] == 'X')
			replace_by(map, num, i - 1, j);
	}
}

void	replace_map(char map[1024][1024], int sizei, int sizej)
{
	int		i;
	int		j = 0;
	char	num = '/';

	while (j < sizej)
	{
		i = 0;
		while (i < sizei)
		{
			if (map[j][i] == 'X')
				replace_by(map, ++num, i, j);
			i++;
		}
		j++;
	}
	j = 0;
	while (j < sizej)
	{
		i = 0;
		while (i < sizei)
		{
			write(1, &map[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}

}

void	replace_islands(char *file)
{
	int		fd;
	char	c;
	int		last;
	char	tab[1024][1024] = {0};
	int		i = 0;
	int		j = 0;
	int		size = -1;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "\n", 1);
		return ;
	}
	last = 0;
	while (read(fd, &c, 1))
	{
		if (c != '\n')
			tab[j][i++] = c;
		else
		{
			j++;
			if (size == -1)
				size = i;
			i = 0;
		}
	}
	replace_map(tab, size, j);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		replace_islands(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
