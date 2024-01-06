/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:07:17 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 15:59:41 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_dlist **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_dlist **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_dlist **a, t_dlist **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
