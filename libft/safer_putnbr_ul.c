/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safer_putnbr_ul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:40:52 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/20 15:53:48 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	safer_putnbr_ul(unsigned long n)
{
	int	written;
	int	placeholder;

	written = 0;
	if (n >= 10)
	{
		placeholder = safer_putnbr_ul(n / 10);
		if (placeholder < 0)
			return (-1);
		written += placeholder;
	}
	if (safer_putchar(n % 10 + '0') < 0)
		return (-1);
	written++;
	return (written);
}
