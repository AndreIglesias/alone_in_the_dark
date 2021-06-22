/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:52:50 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/22 20:10:08 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

/* tests */

#include <stdio.h>
#include <stdlib.h>

void	put_element(void *a)
{
	printf("- %s\n", (char *)a);
}

void	add_to_head(char *str, t_list **head)
{
	t_list *tmp;

	if (!*head)
	{
		*head = (t_list *)malloc(sizeof(t_list));
		(*head)->next = NULL;
		(*head)->data = str;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_list *)malloc(sizeof(t_list));
	tmp->next->next = NULL;
	tmp->next->data = str;
}

int	main(int ac, char **av)
{
	t_list	*head;

	head = NULL;
	for (int i = 1; i < ac; i++)
		add_to_head(av[i], &head);
	ft_list_foreach(head, &put_element);
	return (0);
}
