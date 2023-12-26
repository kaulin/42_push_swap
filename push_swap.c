/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:40:50 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/26 14:17:53 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stacks(t_list **a, t_list **b, int n)
{
	t_list	*node_a;
	t_list	*node_b;
	
	node_a = *a;
	node_b = *b;
	ft_printf("There are %d nodes in the stacks.\n", n);
	ft_printf("A | B\n_________________\n");
	while (node_a || node_b)
	{
		if (node_a && node_b)
			ft_printf("%d | %d\n", node_a->content, node_b->content);
		else if (node_a)
			ft_printf("%d | -\n", node_a->content);
		else
			ft_printf("- | %d\n", node_b->content);
		if (node_a)
			node_a = node_a->next;
		if (node_b)
			node_b = node_b->next;
	}
}

void	push_swap(t_list **a, t_list **b, int n)
{
	print_stacks(a, b, n);
}