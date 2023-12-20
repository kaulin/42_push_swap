/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safer_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:40:52 by jajuntti          #+#    #+#             */
/*   Updated: 2023/11/26 12:29:53 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	safer_putnbr(int n)
{
	int	written;
	int	placeholder;

	written = 0;
	if (n == -2147483648)
		return (safer_putstr("-2147483648"));
	if (n < 0)
	{
		if (safer_putchar('-') < 0)
			return (-1);
		n *= -1;
		written++;
	}
	if (n >= 10)
	{
		placeholder = safer_putnbr(n / 10);
		if (placeholder < 0)
			return (-1);
		written += placeholder;
	}
	placeholder = n % 10 + '0';
	if (safer_putchar(placeholder) < 0)
		return (-1);
	written++;
	return (written);
}
