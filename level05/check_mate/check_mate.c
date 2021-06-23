/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:49:56 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/24 00:08:52 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct s_pos
{
	int	y;
	int	x;
}	t_pos;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_pos	king_pos(char **map, t_pos size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (map[i][j] == 'K')
				return ((t_pos){i, j});
			j++;
		}
		i++;
	}
	return ((t_pos){-1, -1});
}

int		find_steps(char **map, t_pos size, t_pos pos, t_pos steps, char find)
{
	while (0 <= pos.y && pos.y < size.y &&
		   0 <= pos.x && pos.x < size.x)
	{
		if (map[pos.y][pos.x] == find)
			return (1);
		pos.x += steps.x;
		pos.y += steps.y;
	}
	return (0);
}

int		pawn(char **map, t_pos size, t_pos king)
{
	if (king.y < size.y)
	{
		if (king.x < size.x && map[king.y + 1][king.x + 1] == 'P')
			return (1);
		if (king.x > 0 && map[king.y + 1][king.x - 1] == 'P')
			return (1);
	}
	return (0);
}

int		bishop(char **map, t_pos size, t_pos king)
{
	int	i = 0;

	i += find_steps(map, size, king, (t_pos){-1, -1}, 'B');
	i += find_steps(map, size, king, (t_pos){1, -1}, 'B');
	i += find_steps(map, size, king, (t_pos){-1, 1}, 'B');
	i += find_steps(map, size, king, (t_pos){1, 1}, 'B');
	return (i > 0);
}

int		rook(char **map, t_pos size, t_pos king)
{
	int	i = 0;

	i += find_steps(map, size, king, (t_pos){-1, 0}, 'R');
	i += find_steps(map, size, king, (t_pos){1, 0}, 'R');
	i += find_steps(map, size, king, (t_pos){0, 1}, 'R');
	i += find_steps(map, size, king, (t_pos){0, -1}, 'R');
	return (i > 0);
}

int		queen(char **map, t_pos size, t_pos king)
{
	int	i = 0;

	i += find_steps(map, size, king, (t_pos){-1, 0}, 'Q');
	i += find_steps(map, size, king, (t_pos){1, 0}, 'Q');
	i += find_steps(map, size, king, (t_pos){0, 1}, 'Q');
	i += find_steps(map, size, king, (t_pos){0, -1}, 'Q');

	i += find_steps(map, size, king, (t_pos){-1, -1}, 'Q');
	i += find_steps(map, size, king, (t_pos){1, -1}, 'Q');
	i += find_steps(map, size, king, (t_pos){-1, 1}, 'Q');
	i += find_steps(map, size, king, (t_pos){1, 1}, 'Q');

	if (king.y < size.y)
	{
		if (king.x < size.x && map[king.y + 1][king.x + 1] == 'Q')
			return (1);
		if (king.x > 0 && map[king.y + 1][king.x - 1] == 'Q')
			return (1);
	}
	if (0 < king.y)
	{
		if (king.x < size.x && map[king.y - 1][king.x + 1] == 'Q')
			return (1);
		if (king.x > 0 && map[king.y - 1][king.x - 1] == 'Q')
			return (1);
	}
	return (i > 0);
}

void	checkers(char **map, t_pos size)
{
	t_pos king;

	if (size.x == size.y)
	{
		king = king_pos(map, size);
		if (king.x < 0 || king.y < 0)
		{
			write(1, "Fail", 4);
			return ;
		}
		if (pawn(map, size, king) || bishop(map, size, king) ||
			rook(map, size, king) || queen(map, size, king))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	else
		write(1, "Fail", 4);
}

int main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i + 1 < ac)
	{
		if (ft_strlen(av[i]) != ft_strlen(av[i + 1]))
		{
			write(1, "Fail\n", 5);
			return (0);
		}
		i++;
	}
	if (ac > 1)
		checkers(&av[1], (t_pos){ac - 1, ft_strlen(av[1])});
	write(1, "\n", 1);
	return (0);
}
