/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:40:50 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/02 17:38:53 by jajuntti         ###   ########.fr       */
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
*/

static int	check_order(t_list *list)
{
	while (list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

static void	sort_three(t_list **a)
{
	if (check_order(*a))
		return ;
	if ((*a)->content < (*a)->next->content)
	{
		if ((*a)->next->content > (*a)->previous->content
			&& (*a)->content > (*a)->previous->content)
			rra(a);
		else
		{
			rra(a);
			sa(a);
		}
	}
	else if ((*a)->content > (*a)->previous->content)
	{
		if ((*a)->next->content < (*a)->previous->content)
			ra(a);
		else
		{
			ra(a);
			sa(a);
		}
	}
	else
		sa(a);
}

static void	sort_four(t_list **a, t_list **b)
{
	int i;

	i = 0;
	pb(a, b);
	sort_three(a);
	if ((*b)->content > (*a)->previous->content)
	{
		pa(a, b);
		ra(a);
		return;
	}
	while((*b)->content > (*a)->content && i < 3)
	{
		ra(a);
		i++;
	}
	pa(a, b);
	while (i > 0)
	{
		rra(a);
		i--;
	}
}

static void	sort_five(t_list **a, t_list **b)
{
	int i;

	i = 0;
	pb(a, b);
	pb(a, b);
	sort_three(a);
	if ((*b)->content > (*b)->next->content)
		rb(b);
	while(*b && i < 3)
	{
		if ((*b)->content < (*a)->content || i == 2)
		{
			pa(a, b);
		}
		ra(a);
		i++;
	}
	while (i > 0)
	{
		rra(a);
		i--;
	}
}

int	push_swap(int n, char *str[])
{
	t_list	*a;
	t_list	*b;

	a = make_list(n, str);
	if (!a)
		return (1);
	b = NULL;
	if (check_order(a))
		return (0);
	if (n == 2)
		ra(&a);
	if (n == 3)
		sort_three(&a);
	if (n == 4)
		sort_four(&a, &b);
	if (n == 5)
		sort_five(&a, &b);
	dl_lstclear(&a);
	return (0);
}

// Used libft functions: ft_printf, ft_isdigit, ft_atoi, ft_split, ft_strchr

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