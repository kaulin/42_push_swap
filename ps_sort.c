/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:27:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/26 14:10:13 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_dlist **a, t_dlist **b)
{
	if (check_order(*a) && (*a)->value < (*a)->prev->value)
		return ;
	if ((*a)->value < (*a)->next->value)
	{
		if ((*a)->next->value > (*a)->prev->value
			&& (*a)->value > (*a)->prev->value)
			ps_revrot(a, 'a', b);
		else
		{
			ps_revrot(a, 'a', b);
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

/*
Sorts a list of 4 or 5 elements.
*/
static void	sort_four_or_five(t_dlist **a, t_dlist **b)
{
	int	pushed;

	pushed = dl_lstsize(*a) - 3;
	if (dl_lstsize(*a) == 5 && (*a)->value < (*a)->next->value)
		ps_swap(a, 'a', b);
	while (dl_lstsize(*a) - 3 > 0)
		ps_push(a, b);
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

/*
Sorts the last elements of list a. 
*/
static void	sort_remainder(t_dlist **a, t_dlist **b)
{
	int	pushed;

	pushed = dl_lstsize(*a) - 5;
	while (dl_lstsize(*a) > 5)
		ps_push(a, b);
	sort_four_or_five(a, b);
	while (pushed > 0)
	{
		if ((*a)->value < (*a)->prev->value
			&& ((*b)->value < (*a)->value || (*b)->value > (*a)->prev->value))
		{
			ps_push(b, a);
			pushed--;
		}
		else if ((*b)->value < (*a)->value && (*b)->value > (*a)->prev->value)
		{
			ps_push(b, a);
			pushed--;
		}
		else
			ps_revrot(a, 'a', b);
	}
	min_to_top(a, b);
}

/*
Sorts a list of more than 5 elements.
*/
static void	sort_n(int n, t_dlist **a, t_dlist **b)
{
	int	remainder;

	remainder = 5;
	if (n >= 100)
		remainder = 10;
	while (n > remainder)
	{
		smart_move(a, b, 0);
		n--;
	}
	if (remainder == 5)
		sort_four_or_five(a, b);
	else
		sort_remainder(a, b);
	while (*b)
	{
		if ((*a)->value < (*a)->prev->value
			&& ((*b)->value < (*a)->value || (*b)->value > (*a)->prev->value))
			ps_push(b, a);
		else if ((*b)->value < (*a)->value && (*b)->value > (*a)->prev->value)
			ps_push(b, a);
		else
			ps_revrot(a, 'a', b);
	}
}

/*
Chooses the sorting algorithm based on the number of list elements.
*/
void	sort_control(int n, t_dlist **a, t_dlist **b)
{
	if (n == 2)
		ps_rotate(a, 'a', b);
	else if (n == 3)
		sort_three(a, b);
	else if (n <= 5)
		sort_four_or_five(a, b);
	else
		sort_n(n, a, b);
}
