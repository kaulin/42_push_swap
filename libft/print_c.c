/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:12:31 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/20 15:53:48 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_c(t_printer *printer)
{
	char	character;

	character = (char)va_arg(printer->params, int);
	if (safer_putchar(character) < 0)
		return (1);
	printer->output_count++;
	return (0);
}
