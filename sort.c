/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:27:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/05 09:50:27 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* CLEAN THIS UP */
void	sort_three(t_list **a)
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

void	sort_four(t_list **a, t_list **b)
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

void	sort_five(t_list **a, t_list **b)
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

void	sort_n(t_list **a, t_list **b)
{
	if (a == b)
		return;
	return ;
}
