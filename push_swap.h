/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:10:54 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/30 13:04:37 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "dlist.h"

void	sort_n(int n, t_dlist **a, t_dlist **b);
void	smart_move(t_dlist **from, t_dlist **to, int dir);
// void	sort_control(int n, t_dlist **a, t_dlist **b);
void	min_to_top(t_dlist **list, t_dlist **other);
int		check_order(t_dlist *list);
int		m_to_pos_a(t_dlist *list, t_dlist *node);
int		m_to_pos_d(t_dlist *list, t_dlist *node);
int		m_to_top(t_dlist *list, t_dlist *node);
t_dlist	*make_list(char *str[]);
t_dlist	*clean(t_dlist **list);
void	ps_push(t_dlist **from, t_dlist **to);
void	ps_swap(t_dlist **this, char x, t_dlist **other);
void	ps_rotate(t_dlist **this, char x, t_dlist **other);
void	ps_revrot(t_dlist **this, char x, t_dlist **other);

#endif