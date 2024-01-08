/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smart_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:24:09 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/08 11:52:22 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_moves(t_dlist *from, t_dlist *node, t_dlist *to)
{
	int	to_m;
	int	from_m;

	from_m = moves_to_top(from, node);
	to_m = moves_to_pos(to, node);
	if (from_m >= 0 && to_m >= 0)
	{
		if (from_m > to_m)
			return (from_m);
		return (to_m);
	}
	if (from_m < 0 && to_m < 0)
	{
		if (from_m < to_m)
			return (ft_abs(from_m));
		return (ft_abs(to_m));
	}
	return (ft_abs(from_m) + ft_abs(to_m));
}

static void	do_common_moves(t_dlist **from, t_dlist **to, int *from_m, int *to_m)
{
	while (*from_m < 0 && *to_m < 0)
	{
		ps_rrotate(from, 'r', to);
		(*from_m)++;
		(*to_m)++;
	}
	while(from_m > 0 && to_m > 0)
	{
		ps_rotate(from, 'r', to);
		(*from_m)--;
		(*to_m)--;
	}
}

static void	do_moves(t_dlist **from, t_dlist **to, int from_m, int to_m)
{
	do_common_moves(from, to, &from_m, &to_m);
	while (from_m < 0)
	{
		ps_rrotate(from, (*from)->stack, to);
		from_m++;
	}
	while(from_m > 0)
	{
		ps_rotate(from, (*from)->stack, to);
		from_m--;
	}
	while (to_m < 0)
	{
		ps_rrotate(to, (*to)->stack, from);
		to_m++;
	}
	while(to_m > 0)
	{
		ps_rotate(to, (*to)->stack, from);
		to_m--;
	}
}

void	smart_move(t_dlist **from, t_dlist **to)
{
	t_dlist	*node;
	t_dlist	*best;
	int	min_moves;
	int moves;

	node = *from;
	min_moves = get_moves(*from, node, *to);
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
	do_moves(from, to, moves_to_top(*from, best), moves_to_pos(*to, best));
	ps_push(from, to, (*to)->stack);
}
