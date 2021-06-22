/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:17:07 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/22 19:35:12 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	decompose(int nb, int first_time)
{
	int	i;

	i = 2;
	while (i <= nb)
	{
		if (nb % i == 0)
		{
			if (!first_time)
				printf("*");
			printf("%d", i);
			decompose(nb / i, 0);
			return ;
		}
		i++;
	}
	if (i != 2 || !first_time)
		printf("\n");
	else if (first_time)
		printf("%d\n", nb);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		decompose(atoi(av[1]), 1);
	else
		printf("\n");
	return (0);
}
