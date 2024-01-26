/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:20 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/26 12:14:25 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Rotates or reverses until the loop starts with smallest number. Loop has to be 
already in ascending order.
*/
void	min_to_top(t_dlist **list, t_dlist **other)
{
	int		moves;
	int		list_size;
	t_dlist	*node;

	moves = 0;
	list_size = dl_lstsize(*list);
	node = *list;
	if (node->value <= node->prev->value)
		return ;
	while (node->value > node->prev->value)
	{
		node = node->prev;
		moves++;
	}
	while ((*list)->prev->value < (*list)->value)
	{
		if (moves < list_size - moves)
			ps_revrot(list, 'a', other);
		else
			ps_rotate(list, 'a', other);
	}
}
/*
Checks to see if the numbers in the double linked list are in ascending order.
*/
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

int	m_to_top(t_dlist *list, t_dlist *node)
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
		return (moves - n);
}

/*
Returns the number of rotations needed so that the node can be pushed into a
descending list.
*/
int	m_to_pos_d(t_dlist *list, t_dlist *node)
{
	t_dlist	*target;

	if (!list)
		return (0);
	target = list;
	while (target->next)
	{
		if (target->value > target->prev->value \
			&& (node->value > target->value \
			|| node->value < target->prev->value))
			return (m_to_top(list, target));
		if (node->value > target->value && node->value < target->prev->value)
			return (m_to_top(list, target));
		target = target->next;
	}
	return (m_to_top(list, target));
}

/*
Returns the number of rotations needed so that the node can be pushed into an 
ascending list.
*/
int	m_to_pos_a(t_dlist *list, t_dlist *node)
{
	t_dlist	*target;

	if (!list)
		return (0);
	target = list;
	while (target->next)
	{
		if (target->value < target->prev->value \
			&& (node->value < target->value \
			|| node->value > target->prev->value))
			return (m_to_top(list, target));
		if (node->value < target->value && node->value > target->prev->value)
			return (m_to_top(list, target));
		target = target->next;
	}
	return (m_to_top(list, target));
}
