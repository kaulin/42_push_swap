/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:40:50 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/25 09:14:55 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotates or reverses until ordered loop starts with smallest number */
static void	min_to_top(t_dlist **list, t_dlist **other)
{
	int		jumps;
	t_dlist	*node;

	jumps = 0;
	node = *list;
	if (node->value <= node->prev->value)
		return ;
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
			ps_revrot(list, 'a', other);
		else
			ps_rotate(list, 'a', other);
	}
}

int	push_swap(char *str[])
{
	t_dlist	*a;
	t_dlist	*b;
	int		len;

	a = make_list(str);
	if (!a)
		return (1);
	b = NULL;
	len = dl_lstsize(a);
	if (len == 1 || check_order(a))
	{
		min_to_top(&a, &b);
		dl_lstclear(&a);
		return (0);
	}
	sort_control(len, &a, &b);
	min_to_top(&a, &b);
	dl_lstclear(&a);
	return (0);
}
