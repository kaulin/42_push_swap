/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:20 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/08 11:46:18 by jajuntti         ###   ########.fr       */
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
void	min_to_top(t_dlist **list, t_dlist **other)
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
			ps_rrotate(list, 'a', other);
		else
			ps_rotate(list, 'a', other);
	}
}

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
	int		n;
	t_dlist	*target;

	n = dl_lstsize(list);
	target = list;
	if ((node->value < target->value && node->value < target->prev->value)
		|| (node->value > target->value && node->value > target->prev->value))
		return (moves_to_top(list, target));
	while (node->value > target->value && target->next)
		target = target->next;
	return (moves_to_top(list, target));
}