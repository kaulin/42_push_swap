/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smart_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:24:09 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/26 15:24:19 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Checks for and implements a more economic combination of rotations.
*/
static void	double_check(int from_s, int to_s, int *from_m, int *to_m)
{
	int	temp_f;
	int	temp_t;

	temp_f = *from_m;
	temp_t = *to_m;
	if (*to_m == 0 || *from_m == 0)
		return ;
	if ((*from_m > 0 && *to_m > 0) || (*from_m < 0 && *to_m < 0))
		return ;
	if (*from_m > 0 && *from_m - from_s > *to_m)
		temp_f = *from_m - from_s;
	if (*from_m > 0 && to_s + *to_m < *from_m)
		temp_t = to_s + *to_m;
	if (*from_m < 0 && *to_m - to_s > *from_m)
		temp_t = *to_m - to_s;
	if (*from_m < 0 && from_s + *from_m < *to_m)
		temp_f = from_s + *from_m;
	if (ft_abs(temp_f) < ft_abs(temp_t))
		*from_m = temp_f;
	if (ft_abs(temp_f) > ft_abs(temp_t))
		*to_m = temp_t;
}

/*
Returns number of stack rotations required before pushing.
*/
static int	get_moves(t_dlist *from, t_dlist *node, t_dlist *to, int dir)
{
	int	to_m;
	int	from_m;

	from_m = m_to_top(from, node);
	if (dir)
		to_m = m_to_pos_a(to, node);
	else
		to_m = m_to_pos_d(to, node);
	double_check(dl_lstsize(from), dl_lstsize(to), &from_m, &to_m);
	if (from_m == 0 && to_m == 0)
		return (0);
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

/*
If both stacks are rotated in the same direction, use the combined commands.
*/
static void	do_doub_moves(t_dlist **from, t_dlist **to, int *from_m, int *to_m)
{
	while (*from_m < 0 && *to_m < 0)
	{
		ps_revrot(from, 'r', to);
		(*from_m)++;
		(*to_m)++;
	}
	while (*from_m > 0 && *to_m > 0)
	{
		ps_rotate(from, 'r', to);
		(*from_m)--;
		(*to_m)--;
	}
}

/*
Executes the given rotations for both stacks, also checks for double moves.
*/
static void	do_moves(t_dlist **from, t_dlist **to, int from_m, int to_m)
{
	double_check(dl_lstsize(*from), dl_lstsize(*to), &from_m, &to_m);
	do_doub_moves(from, to, &from_m, &to_m);
	while (from_m < 0)
	{
		ps_revrot(from, (*from)->stack, to);
		from_m++;
	}
	while (from_m > 0)
	{
		ps_rotate(from, (*from)->stack, to);
		from_m--;
	}
	while (to_m < 0)
	{
		ps_revrot(to, (*to)->stack, from);
		to_m++;
	}
	while (to_m > 0)
	{
		ps_rotate(to, (*to)->stack, from);
		to_m--;
	}
}

/*
Finds the node that takes the least amount of moves to push to the correct
location and executes those moves.
*/
void	smart_move(t_dlist **from, t_dlist **to, int dir)
{
	t_dlist	*node;
	t_dlist	*best;
	int		min_moves;
	int		moves;

	node = *from;
	min_moves = get_moves(*from, node, *to, dir);
	best = node;
	while (min_moves != 0 && node->next)
	{
		node = node->next;
		moves = get_moves(*from, node, *to, dir);
		if (moves < min_moves)
		{
			min_moves = moves;
			best = node;
		}
	}
	if (dir)
		do_moves(from, to, m_to_top(*from, best), m_to_pos_a(*to, best));
	else
		do_moves(from, to, m_to_top(*from, best), m_to_pos_d(*to, best));
	ps_push(from, to);
}
