/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:10:54 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/07 17:18:51 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "dlist.h"

int		push_swap(int n, char *str[]);
void	sort_control(int n, t_dlist **a, t_dlist **b);
int		check_order(t_dlist *list);
void	min_to_top(t_dlist **list, t_dlist **other);
int		moves_to_position (t_dlist *list, int n, t_dlist *node);
int		moves_to_top(t_dlist *list, int n, t_dlist *node);
void	rotate_n(int jumps, t_dlist **list);
t_dlist	*make_list(int n, char *str[]);
t_dlist	*clean(t_dlist **list);
void	push_x(t_dlist **from, t_dlist **to, char x);
void	swap_x(t_dlist **this, char x, t_dlist **other);
void	rotate_x(t_dlist **this, char x, t_dlist **other);
void	rrotate_x(t_dlist **this, char x, t_dlist **other);

#endif