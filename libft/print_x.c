/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:12:31 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/20 15:53:48 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_x(t_printer *printer)
{
	unsigned long	hex;

	hex = va_arg(printer->params, unsigned int);
	if (*printer->source == 'x')
		printer->status = safer_putnbr_ul_base(hex, "0123456789abcdef");
	else
		printer->status = safer_putnbr_ul_base(hex, "0123456789ABCDEF");
	if (printer->status < 0)
		return (1);
	printer->output_count += printer->status;
	return (0);
}
