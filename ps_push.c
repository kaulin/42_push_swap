/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:56:53 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/22 13:22:30 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **to, t_list **from)
{

	
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pb\n");
}
