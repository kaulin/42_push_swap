/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:10:54 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 12:53:12 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_dlist
{
	int				value;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

int		push_swap(int n, char *str[]);
void	sort_control(int n, t_dlist **a, t_dlist **b);
int		check_order(t_dlist *list);
void	correct_start(t_dlist **list);
void	rotate_n(int jumps, t_dlist **list);
int		find_min(int n, t_dlist *list);
t_dlist	*make_list(int n, char *str[]);
t_dlist	*clean(t_dlist **list);
t_dlist	*dl_lstnew(int value);
void	dl_lstadd_front(t_dlist **lst, t_dlist *new);
void	dl_lstadd_back(t_dlist **lst, t_dlist *new);
int		dl_lstsize(t_dlist *lst);
void	dl_lstclear(t_dlist **lst);
void	sa(t_dlist **a);
void	sb(t_dlist **b);
void	ss(t_dlist **a, t_dlist **b);
void	pa(t_dlist **a, t_dlist **b);
void	pb(t_dlist **a, t_dlist **b);
void	ra(t_dlist **a);
void	rb(t_dlist **b);
void	rr(t_dlist **a, t_dlist **b);
void	rra(t_dlist **a);
void	rrb(t_dlist **b);
void	rrr(t_dlist **a, t_dlist **b);

#endif