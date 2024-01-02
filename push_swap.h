/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:10:54 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/02 13:41:59 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

t_list	*push_swap(int n, char *str[]);
t_list	*make_list(int n, char *str[]);
t_list	*clean(t_list **list);
t_list	*dl_lstnew(int content);
void	print_lists(t_list *a, t_list *b, int n);
void	dl_lstadd_front(t_list **lst, t_list *new);
void	dl_lstadd_back(t_list **lst, t_list *new);
int		dl_lstsize(t_list *lst);
void	dl_lstclear(t_list **lst);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif