/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:40:50 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/10 10:47:21 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotates or reverses until ordered loop starts with smallest number */
static void	min_to_top(t_dlist **list, t_dlist **other)
{
	int		jumps;
	t_dlist	*node;

	jumps = 0;
	node = *list;
	while (node->value > node->prev->value)
	{
		node = node->prev;
		jumps++;
	}
	node = *list;
	while (node->next && node->value < node->next->value)
	{
		node = node->next;
		jumps--;
	}
	while ((*list)->prev->value < (*list)->value)
	{
		if (jumps < 0)
			ps_revrot(list, 'a', other);
		else
			ps_rotate(list, 'a', other);
	}
}

int	push_swap(int n, char *str[])
{
	t_dlist	*a;
	t_dlist	*b;

	a = make_list(n, str);
	if (!a)
		return (1);
	b = NULL;
	if (n == 1 || (check_order(a) && a->value < a->prev->value))
	{
		dl_lstclear(&a);
		return (0);
	}
	if (check_order(a))
	{
		min_to_top(&a, &b);
		dl_lstclear(&a);
		return (0);
	}
	sort_control(n, &a, &b);
	min_to_top(&a, &b);
	dl_lstclear(&a);
	return (0);
}

// Used libft functions: ft_putendl_fd, ft_putchar_fd, ft_putstr_fd, ft_abs, ft_isdigit, ft_atol, ft_split, ft_strchr

/*
required: sort   3 numbers with <=     3 operations
required: sort   5 numbers with <=    12 operations
scored:   sort 100 numbers with <=   700 operations   max score
                                     900 operations
                                    1100 operations
                                    1300 operations
                                    1500 operations   min score
scored:   sort 500 numbers with <=  5500 operations   max score
                                    7000 operations
                                    8500 operations
                                   10000 operations
                                   11500 operations   min score
*/

/* Test all ps language operators
	print_dlists(a, b, n);
	pb(&a, &b);
	print_dlists(a, b, n);
	ra(&a);
	print_dlists(a, b, n);
	sa(&a);
	print_dlists(a, b, n);
	pb(&a, &b);
	print_dlists(a, b, n);
	rra(&b);
	print_dlists(a, b, n);
*/