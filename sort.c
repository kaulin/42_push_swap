/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:27:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/05 14:55:06 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* CLEAN THIS UP */
static void	sort_three(t_list **a)
{
	if (check_order(*a) && (*a)->content < (*a)->previous->content)
		return ;
	if ((*a)->content < (*a)->next->content)
	{
		if ((*a)->next->content > (*a)->previous->content
			&& (*a)->content > (*a)->previous->content)
			rra(a);
		else
		{
			rra(a);
			sa(a);
		}
	}
	else if ((*a)->content > (*a)->previous->content)
	{
		if ((*a)->next->content < (*a)->previous->content)
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

static void	sort_four(t_list **a, t_list **b)
{
	pb(a, b);
	sort_three(a);
	if ((*b)->content > (*a)->previous->content)
	{
		pa(a, b);
		ra(a);
	}
	else
	{
		while ((*b)->content > (*a)->content)
			ra(a);
		pa(a, b);
	}
	correct_start(a);
}

static void	sort_five(t_list **a, t_list **b)
{
	pb(a, b);
	pb(a, b);
	sort_three(a);
	if ((*b)->content > (*b)->next->content)
		rb(b);
	while (*b)
	{
		if ((*b)->content < (*a)->content)
			pa(a, b);
		else if ((*b)->content > (*a)->previous->content
			&& (*a)->previous->content > (*a)->content)
		{
			pa(a, b);
			ra(a);
		}
		else
			ra(a);
	}
	correct_start(a);
}

static void	sort_n(int n, t_list **a, t_list **b)
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

void	sort_control(int n, t_list **a, t_list **b)
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