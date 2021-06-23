/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:29:34 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/23 09:00:32 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*erase;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list && !(*cmp)((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	tmp = *begin_list;
	while (tmp->next)
	{
		if (!(*cmp)(tmp->next->data, data_ref))
		{
			erase = tmp->next;
			tmp->next = tmp->next->next;
			free(erase);
		}
		tmp = tmp->next;
	}
}

/* tests */

#include <string.h>

void add_node(t_list **head, char *str)
{
	t_list	*tmp;
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

int	main(void)
{
	t_list	*head;

	head = NULL;
	add_node(&head, "1st_one");
	add_node(&head, "2nd_one");
	add_node(&head, "3rd_one");
	add_node(&head, "4th_one");
	ft_list_remove_if(&head, "3rd_one", &strcmp);
	while (head)
	{
		printf("%s ", (char *)head->data);
		head = head->next;
	}
	return (0);
}
