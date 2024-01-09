/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:10:54 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/09 08:01:54 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "dlist.h"

int		push_swap(int n, char *str[]);
void	smart_move(t_dlist **from, t_dlist **to);
void	sort_control(int n, t_dlist **a, t_dlist **b);
int		check_order(t_dlist *list);
int		moves_to_pos(t_dlist *list, t_dlist *node);
int		moves_to_top(t_dlist *list, t_dlist *node);
t_dlist	*make_list(int n, char *str[]);
t_dlist	*clean(t_dlist **list);
void	ps_push(t_dlist **from, t_dlist **to);
void	ps_swap(t_dlist **this, char x, t_dlist **other);
void	ps_rotate(t_dlist **this, char x, t_dlist **other);
void	ps_rrotate(t_dlist **this, char x, t_dlist **other);
void	print_dlist(t_dlist *list);
void	print_dlists(t_dlist *a, t_dlist *b);

#endif