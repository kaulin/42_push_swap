/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:20 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/07 17:17:52 by jajuntti         ###   ########.fr       */
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
			rrotate_x(list, 'a', other);
		else
			rotate_x(list, 'a', other);
	}
}

int	moves_to_top(t_dlist *list, int n, t_dlist *node)
{
	int	moves;

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

int	moves_to_position (t_dlist *list, int n, t_dlist *node)
{
	t_dlist	*target;

	target = list;
	if ((node->value < target->value && node->value < target->prev->value)
		|| (node->value > target->value && node->value > target->prev->value))
		return (moves_to_top(list, n, target));
	while (node->value > target->value && target->next)
		target = target->next;
	return (moves_to_top(list, n, target));
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