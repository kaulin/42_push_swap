/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:28:40 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/08 10:20:21 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push(t_dlist **from, t_dlist **to, char x)
{
	(*from)->stack = (*to)->stack;
	push(from, to);
	ft_printf("p%c\n", x);
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
	if (x != 'r')
		rotate(this);
	else
	{
		rotate(this);
		rotate(other);
	}
	ft_printf("r%c\n", x);
}

void	ps_rrotate(t_dlist **this, char x, t_dlist **other)
{
	if (x != 'r')
		rrotate(this);
	else
	{
		rrotate(this);
		rrotate(other);
	}
	ft_printf("rr%c\n", x);
}