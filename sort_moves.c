/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:28:40 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/07 17:07:01 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_x(t_dlist **from, t_dlist **to, char x)
{
	push(from, to);
	ft_printf("p%c\n", x);
}

void	swap_x(t_dlist **this, char x, t_dlist **other)
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

void	rotate_x(t_dlist **this, char x, t_dlist **other)
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

void	rrotate_x(t_dlist **this, char x, t_dlist **other)
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