/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:28:40 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/10 11:00:53 by jajuntti         ###   ########.fr       */
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
	ft_putstr_fd("p", 1);
	ft_putchar_fd((*to)->stack, 1);
	ft_putstr_fd("\n", 1);
	//ft_printf("p%c\n", (*to)->stack);
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
	ft_putstr_fd("s", 1);
	ft_putchar_fd(x, 1);
	ft_putstr_fd("\n", 1);
	//ft_printf("s%c\n", x);
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
	ft_putstr_fd("r", 1);
	ft_putchar_fd(x, 1);
	ft_putstr_fd("\n", 1);
	//ft_printf("r%c\n", x);
}

void	ps_revrot(t_dlist **this, char x, t_dlist **other)
{
	if (x == 'r')
	{
		revrot(this);
		revrot(other);
	}
	else
		revrot(this);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(x, 1);
	ft_putstr_fd("\n", 1);
	//ft_printf("rr%c\n", x);
}
