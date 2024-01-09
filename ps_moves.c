/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:28:40 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/09 07:55:39 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push(t_dlist **from, t_dlist **to)
{
	if ((*from)->stack == 'a')
		(*from)->stack = 'b';
	else
		(*from)->stack = 'a';
	push(from, to);
	ft_printf("p%c\n", (*to)->stack);
}

void	ps_swap(t_dlist **this, char x, t_dlist **other)
{
	if (x != 's')
		swap(this);
	else
	{
		swap(this);
		swap(other);
	}
	ft_printf("s%c\n", x);
}

void	ps_rotate(t_dlist **this, char x, t_dlist **other)
{
	if (x == 'r')
	{
		rotate(this);
		rotate(other);
	}
	else
		rotate(this);
	ft_printf("r%c\n", x);
}

void	ps_rrotate(t_dlist **this, char x, t_dlist **other)
{
	if (x == 'r')
	{
		rrotate(this);
		rrotate(other);
	}
	else
		rrotate(this);
	ft_printf("rr%c\n", x);
}
