/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:20 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/08 17:21:23 by jajuntti         ###   ########.fr       */
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
/*
static int	find_maxval(t_dlist *list)
{
	int	maxval;

	maxval = list->value;
	while (list->next)
	{
		list = list->next;
		if (list->value > maxval)
			maxval = list->value;
	}
	return (maxval);
}

static int	find_minval(t_dlist *list)
{
	int	minval;

	minval = list->value;
	while (list->next)
	{
		list = list->next;
		if (list->value < minval)
			minval = list->value;
	}
	return (minval);
}
*/

int	moves_to_top(t_dlist *list, t_dlist *node)
{
	int	n;
	int	moves;

	n = dl_lstsize(list);
	moves = 0;
	while (list != node)
	{
		moves++;
		list = list->next;
	}
	if (moves < n - moves)
		return (moves);
	else
		return (-1 * (n - moves));
}

int	moves_to_pos (t_dlist *list, t_dlist *node)
{
	t_dlist	*target;

	if (!list)
		return (0);
	target = list;
	while (target->next)
	{
		if (node->value > target->prev->value && target->prev->value > target->value)
			return (moves_to_top(list, target));
		if (node->value < target->value && target->prev->value > target->value)
			return (moves_to_top(list, target));
		if (node->value > target->prev->value && node->value < target->value)
			return (moves_to_top(list, target));
		target = target->next;
	}
	return (moves_to_top(list, target));
}