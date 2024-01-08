/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:27:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/08 18:03:59 by jajuntti         ###   ########.fr       */
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
			ps_rrotate(a, 'a', b);
		else
		{
			ps_rrotate(a, 'a', b);
			ps_swap(a, 'a', b);
		}
	}
	else if ((*a)->value > (*a)->prev->value)
	{
		if ((*a)->next->value < (*a)->prev->value)
			ps_rotate(a, 'a', b);
		else
		{
			ps_rotate(a, 'a', b);
			ps_swap(a, 'a', b);
		}
	}
	else
		ps_swap(a, 'a', b);
}

static void	sort_four(t_dlist **a, t_dlist **b)
{
	ps_push(a, b);
	sort_three(a, b);
	if ((*b)->value > (*a)->prev->value)
	{
		ps_push(b, a);
		ps_rotate(a, 'a', b);
	}
	else
	{
		while ((*b)->value > (*a)->value)
			ps_rotate(a, 'a', b);
		ps_push(b, a);
	}
}

static void	sort_five(t_dlist **a, t_dlist **b)
{
	int	pushed;

	if ((*a)->value < (*a)->next->value)
		ps_swap(a, 'a', b);
	ps_push(a, b);
	ps_push(a, b);
	pushed = 2;
	sort_three(a, b);
	while (pushed > 0)
	{
		if ((*b)->value < (*a)->value)
		{
			ps_push(b, a);
			pushed--;
		}
		else if ((*b)->value > (*a)->prev->value
			&& (*a)->prev->value > (*a)->value)
		{
			ps_push(b, a);
			pushed--;
			ps_rotate(a, 'a', b);
		}
		else
			ps_rotate(a, 'a', b);
	}
}

static void	sort_n(int n, t_dlist **a, t_dlist **b)
{
	while (n > 5)
	{
		ps_push(a, b);
		//smart_move(a, b);
		n--;
	}
	sort_five(a, b);
	while (*b)
	{
		smart_move(b, a);
	}
}

void	sort_control(int n, t_dlist **a, t_dlist **b)
{
	if (n == 2)
		ps_rotate(a, 'a', b);
	if (n == 3)
		sort_three(a, b);
	if (n == 4)
		sort_four(a, b);
	if (n == 5)
		sort_five(a, b);
	if (n > 5)
		sort_n(n, a, b);
}