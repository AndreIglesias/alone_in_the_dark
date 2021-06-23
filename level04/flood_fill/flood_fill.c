/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 00:54:14 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/23 08:27:25 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

static void	fill(char **tab, t_point size, t_point p, char zone)
{
	if (0 <= p.x && p.x < size.x && 0 <= p.y && p.y < size.y
		&& tab[p.y][p.x] == zone)
	{
		tab[p.y][p.x] = 'F';
		fill(tab, size, (t_point){p.x - 1, p.y}, zone);
		fill(tab, size, (t_point){p.x + 1, p.y}, zone);
		fill(tab, size, (t_point){p.x, p.y - 1}, zone);
		fill(tab, size, (t_point){p.x, p.y + 1}, zone);
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

/* tests */

char** make_area(char** zone, t_point size)
{
        char** new;

        new = malloc(sizeof(char*) * size.y);
        for (int i = 0; i < size.y; ++i)
        {
                new[i] = malloc(size.x + 1);
                for (int j = 0; j < size.x; ++j)
                        new[i][j] = zone[i][j];
                new[i][size.x] = '\0';
        }

        return new;
}

int main(void)
{
        t_point size = {8, 5};
        char *zone[] = {
                "11111111",
                "10001001",
                "10010001",
                "10110001",
                "11100001",
        };

        char**  area = make_area(zone, size);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        printf("\n");

        t_point begin = {7, 4};
        flood_fill(area, size, begin);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        return (0);
}
