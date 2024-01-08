/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:27:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/08 08:44:43 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* CLEAN THIS UP */
static void	sort_three(t_dlist **a, t_dlist **b)
{
	if (check_order(*a) && (*a)->value < (*a)->prev->value)
		return ;
	if ((*a)->value < (*a)->next->value)
	{
		if ((*a)->next->value > (*a)->prev->value
			&& (*a)->value > (*a)->prev->value)
			rrotate_x(a, 'a', b);
		else
		{
			rrotate_x(a, 'a', b);
			swap_x(a, 'a', b);
		}
	}
	else if ((*a)->value > (*a)->prev->value)
	{
		if ((*a)->next->value < (*a)->prev->value)
			rotate_x(a, 'a', b);
		else
		{
			rrotate_x(a, 'a', b);
			swap_x(a, 'a', b);
		}
	}
	else
		swap_x(a, 'a', b);
}

static void	sort_four(t_dlist **a, t_dlist **b)
{
	push_x(a, b, 'b');
	sort_three(a, b);
	if ((*b)->value > (*a)->prev->value)
	{
		push_x(b, a, 'a');
		rotate_x(a, 'a', b);
	}
	else
	{
		while ((*b)->value > (*a)->value)
			rotate_x(a, 'a', b);
		pa(b, a);
	}
	min_to_top(a);
}

static void	sort_five(t_dlist **a, t_dlist **b)
{
	pb(a, b);
	pb(a, b);
	sort_three(a);
	if ((*b)->value > (*b)->next->value)
		rotate_x(b, 'b', a);
	while (*b)
	{
		if ((*b)->value < (*a)->value)
			push_x(b, a, 'a');
		else if ((*b)->value > (*a)->prev->value
			&& (*a)->prev->value > (*a)->value)
		{
			push_x(b, a, 'a');
			rotate_x(a, 'a', b);
		}
		else
			rotate_x(a, 'a', b);
	}
	min_to_top(a, b);
}

int	get_moves(t_dlist *from, t_dlist *node, t_dlist *to)
{
	int	to_moves;
	int	from_moves;

	from_moves = moves_to_top(from, dl_lstsize(from), node);
	to_moves = moves_to_position(to, dl_lstsize(to), node);
	if (from_moves >= 0 && to_moves >= 0)
	{
		if (from_moves > to_moves)
			return (from_moves);
		return (to_moves);
	}
	if (from_moves < 0 && to_moves < 0)
	{
		if (from_moves < to_moves)
			return (-1 * from_moves);
		return (-1 * to_moves);
	}
	return ()
}

void	smart_move(t_dlist **from, char f, t_dlist **to, char t)
{
	t_dlist	*node;
	t_dlist	*best;
	int	min_moves;
	int moves;

	node = *from;
	min_moves = dl_lstsize(*from) + dl_lstsize(*to);
	best = node;
	while(node->next)
	{
		node = node->next;
		moves = get_moves(*from, node, *to);
		if (moves < min_moves)
		{
			min_moves = moves;
			best = node;
		}
	}
	do_moves(from, f, to, t, best)
	push_x(to, t, from);
}

static void	sort_n(int n, t_dlist **a, t_dlist **b)
{
	while (n > 3)
	{
		smart_move(a, 'a', b, 'b');
		n--;
	}
	sort_three(a, b);
	while (*b)
	{
		smart_move(b, 'b', a, 'a');
	}
	min_to_top(a, b);
}

void	sort_control(int n, t_dlist **a, t_dlist **b)
{
	if (n == 2)
		ra(a);
	if (n == 3)
		sort_three(a, b);
	if (n == 4)
		sort_four(a, b);
	if (n == 5)
		sort_five(a, b);
	if (n > 5)
		sort_n(n, a, b);
}