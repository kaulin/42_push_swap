/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:20 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/05 14:20:03 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Check to see if the numbers in the loop are in ascending order. */
int	check_order(t_list *list)
{
	t_list	*min;
	t_list	*node;

	node = list;
	while (node->content > node->previous->content)
		node = node->previous;
	min = node;
	node = list;
	while (node->next && node->content < node->next->content)
		node = node->next;
	return (node == min->previous);
}

/* Rotates or reverses until ordered loop starts with smallest number */
void	correct_start(t_list **list)
{
	int		jumps;
	t_list	*node;

	jumps = 0;
	node = *list;
	while (node->content > node->previous->content)
	{
		node = node->previous;
		jumps++;
	}
	node = *list;
	while (node->next && node->content < node->next->content)
	{
		node = node->next;
		jumps--;
	}
	while ((*list)->previous->content < (*list)->content)
	{
		if (jumps < 0)
			rra(list);
		else
			ra(list);
	}
}

int	find_min(int n, t_list *list)
{
	int	min;
	int	jumps;
	int	jumps_to_min;

	min = list->content;
	jumps = 0;
	jumps_to_min = 0;
	list = list->next;
	while (list)
	{
		jumps++;
		if (list->content < min)
		{
			min = list->content;
			jumps_to_min = jumps;
		}
		list = list->next;
	}
	if (jumps_to_min < n - jumps_to_min)
		return (jumps_to_min);
	else
		return (-1 * (n - jumps_to_min));
}

void	rotate_n(int jumps, t_list **list)
{
	while(jumps != 0)
	{
		if (jumps > 0)
		{
			ra(list);
			jumps--;
		}
		else
		{
			rra(list);
			jumps++;
		}
	}
}