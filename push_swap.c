/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:40:50 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 12:53:07 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void print_dlists(t_dlist *a, t_dlist *b)
{
	ft_printf("---\nA: %d\n", dl_lstsize(a));
	while (a)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}
	ft_printf("---\nB: %d\n", dl_lstsize(b));
	while (b)
	{
		ft_printf("%d\n", b->value);
		b = b->next;
	}
	ft_printf("---\n\n");
}

static void print_dlist(t_dlist *list)
{
	while (list)
	{
		ft_printf("%d ", list->value);
		list = list->next;
	}
	ft_printf("\n\n");
	
}
*/

#include "push_swap.h"

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
		correct_start(&a);
		dl_lstclear(&a);
		return (0);
	}
	sort_control(n, &a, &b);
	dl_lstclear(&a);
	return (0);
}

// Used libft functions: ft_printf, ft_isdigit, ft_atoi, ft_atol, ft_split, ft_strchr

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