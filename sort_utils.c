/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:20 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 12:53:07 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Check to see if the numbers in the loop are in ascending order. */
int	check_order(t_dlist *list)
{
	t_dlist	*min;
	t_dlist	*node;

	node = list;
	while (node->value > node->prev->value)
		node = node->prev;
	min = node;
	node = list;
	while (node->next && node->value < node->next->value)
		node = node->next;
	return (node == min->prev);
}

/* Rotates or reverses until ordered loop starts with smallest number */
void	correct_start(t_dlist **list)
{
	int		jumps;
	t_dlist	*node;

	jumps = 0;
	node = *list;
	while (node->value > node->prev->value)
	{
		node = node->prev;
		jumps++;
	}
	node = *list;
	while (node->next && node->value < node->next->value)
	{
		node = node->next;
		jumps--;
	}
	while ((*list)->prev->value < (*list)->value)
	{
		if (jumps < 0)
			rra(list);
		else
			ra(list);
	}
}

int	find_min(int n, t_dlist *list)
{
	int	min;
	int	jumps;
	int	jumps_to_min;

	min = list->value;
	jumps = 0;
	jumps_to_min = 0;
	list = list->next;
	while (list)
	{
		jumps++;
		if (list->value < min)
		{
			min = list->value;
			jumps_to_min = jumps;
		}
		list = list->next;
	}
	if (jumps_to_min < n - jumps_to_min)
		return (jumps_to_min);
	else
		return (-1 * (n - jumps_to_min));
}

void	rotate_n(int jumps, t_dlist **list)
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