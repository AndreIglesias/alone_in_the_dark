/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:08:16 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/22 22:21:52 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sort_int_tab(int *tab, unsigned int size)
{
	int	i;
	int j;
	int	tmp;

	if (!tab || size < 2)
		return ;
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

/* tests */

#include <stdlib.h>
#include <stdio.h>

void print_tab(int *tab, unsigned int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
}

int main(int ac, char **av)
{
	int	*tab;

	tab = (int *)malloc(sizeof(int) * 100000);
	for (int i = 1; i < ac; i++)
		tab[i - 1] = atoi(av[i]);
	sort_int_tab(tab, ac - 1);
	print_tab(tab, ac - 1);
	return (0);
}
