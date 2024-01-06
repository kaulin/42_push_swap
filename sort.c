/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:27:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 12:53:07 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* CLEAN THIS UP */
static void	sort_three(t_dlist **a)
{
	if (check_order(*a) && (*a)->value < (*a)->prev->value)
		return ;
	if ((*a)->value < (*a)->next->value)
	{
		if ((*a)->next->value > (*a)->prev->value
			&& (*a)->value > (*a)->prev->value)
			rra(a);
		else
		{
			rra(a);
			sa(a);
		}
	}
	else if ((*a)->value > (*a)->prev->value)
	{
		if ((*a)->next->value < (*a)->prev->value)
			ra(a);
		else
		{
			ra(a);
			sa(a);
		}
	}
	else
		sa(a);
}

static void	sort_four(t_dlist **a, t_dlist **b)
{
	pb(a, b);
	sort_three(a);
	if ((*b)->value > (*a)->prev->value)
	{
		pa(a, b);
		ra(a);
	}
	else
	{
		while ((*b)->value > (*a)->value)
			ra(a);
		pa(a, b);
	}
	correct_start(a);
}

static void	sort_five(t_dlist **a, t_dlist **b)
{
	pb(a, b);
	pb(a, b);
	sort_three(a);
	if ((*b)->value > (*b)->next->value)
		rb(b);
	while (*b)
	{
		if ((*b)->value < (*a)->value)
			pa(a, b);
		else if ((*b)->value > (*a)->prev->value
			&& (*a)->prev->value > (*a)->value)
		{
			pa(a, b);
			ra(a);
		}
		else
			ra(a);
	}
	correct_start(a);
}

static void	sort_n(int n, t_dlist **a, t_dlist **b)
{
	int	jumps_to_min;

	while (n)
	{
		jumps_to_min = find_min(n, *a);
		rotate_n(jumps_to_min, a);
		pb(a, b);
		n--;
	}
	while (*b)
	{
		pa(a, b);
	}
	return ;
}

void	sort_control(int n, t_dlist **a, t_dlist **b)
{
	if (n == 2)
		ra(a);
	if (n == 3)
		sort_three(a);
	if (n == 4)
		sort_four(a, b);
	if (n == 5)
		sort_five(a, b);
	if (n > 5)
		sort_n(n, a, b);
}