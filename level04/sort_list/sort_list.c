/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:23:57 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/22 23:20:11 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*i;
	t_list	*j;
	int		swap;

	if (!lst || !lst->next)
		return (lst);
	i = lst;
	while (i)
	{
		j = i;
		while (j)
		{
			if (!(*cmp)(i->data, j->data))
			{
				swap = j->data;
				j->data = i->data;
				i->data = swap;
			}
			j = j->next;
		}
		i = i->next;
	}
	return (lst);
}

/* tests */

#include <stdlib.h>
#include <stdio.h>

void	add_int(int i, t_list **head)
{
	t_list *tmp;

	if (!*head)
	{
		*head = (t_list *)malloc(sizeof(t_list));
		(*head)->data = i;
		(*head)->next = NULL;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_list *)malloc(sizeof(t_list));
	tmp->next->data = i;
	tmp->next->next = NULL;
}

void	put_list(t_list *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int ascending(int a, int b)
{
	return (a <= b);
}

int	main(int ac, char **av)
{
	t_list	*head;

	head = NULL;
	for (int i = 1; i < ac; i++)
		add_int(atoi(av[i]), &head);
	head = sort_list(head, &ascending);
	put_list(head);
	return (0);
}
