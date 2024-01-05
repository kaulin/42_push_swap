/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:40:50 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/05 09:51:10 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void print_lists(t_list *a, t_list *b)
{
	ft_printf("---\nA: %d\n", dl_lstsize(a));
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
	ft_printf("---\nB: %d\n", dl_lstsize(b));
	while (b)
	{
		ft_printf("%d\n", b->content);
		b = b->next;
	}
	ft_printf("---\n\n");
}

static void print_list(t_list *list)
{
	while (list)
	{
		ft_printf("%d ", list->content);
		list = list->next;
	}
	ft_printf("\n\n");
	
}
*/

#include "push_swap.h"

/*	Check to see if the numbers in the loop are in ascending order. */
int	check_order(t_list *list)
{
	t_list	*min;
	t_list	*node;

	node = list;
	while (node->content > node->previous->content)
		node = node->previous;
	min = node;
	node = list;
	while (node->next && node->content < node->next->content)
		node = node->next;
	return (node == min->previous);
}

/* Rotates or reverses until ordered loop starts with smallest number */
void	correct_start(t_list **list)
{
	int		jumps;
	t_list	*node;

	jumps = 0;
	node = *list;
	while (node->content > node->previous->content)
	{
		node = node->previous;
		jumps++;
	}
	node = *list;
	while (node->next && node->content < node->next->content)
	{
		node = node->next;
		jumps--;
	}
	while ((*list)->previous->content < (*list)->content)
	{
		if (jumps < 0)
			rra(list);
		else
			ra(list);
	}
}

static void	sort_control(int n, t_list **a, t_list **b)
{
	if (n == 2)
		ra(&a);
	if (n == 3)
		sort_three(&a);
	if (n == 4)
		sort_four(&a, &b);
	if (n == 5)
		sort_five(&a, &b);	
}

int	push_swap(int n, char *str[])
{
	t_list	*a;
	t_list	*b;

	a = make_list(n, str);
	if (!a)
		return (1);
	b = NULL;
	if (n == 1 || (check_order(a) && a->content < a->previous->content))
		return (0);
	if (check_order(a))
	{
		correct_start(&a);
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
	print_lists(a, b, n);
	pb(&a, &b);
	print_lists(a, b, n);
	ra(&a);
	print_lists(a, b, n);
	sa(&a);
	print_lists(a, b, n);
	pb(&a, &b);
	print_lists(a, b, n);
	rra(&b);
	print_lists(a, b, n);
*/