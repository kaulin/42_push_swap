/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:56:16 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/08 10:36:56 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <stdlib.h>

typedef struct s_dlist
{
	int				value;
	struct s_dlist	*prev;
	struct s_dlist	*next;
	char			stack;
}	t_dlist;

t_dlist	*dl_lstnew(int value);
void	dl_lstadd_front(t_dlist **lst, t_dlist *new);
void	dl_lstadd_back(t_dlist **lst, t_dlist *new);
int		dl_lstsize(t_dlist *lst);
void	dl_lstclear(t_dlist **lst);
void	push(t_dlist **to, t_dlist **from);
void	swap(t_dlist **list);
void	rotate(t_dlist **list);
void	rrotate(t_dlist **list);

#endif