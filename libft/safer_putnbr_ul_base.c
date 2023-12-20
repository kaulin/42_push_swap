/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safer_putnbr_ul_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:40:52 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/20 15:53:48 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	safer_putnbr_ul_base(unsigned long n, char *base)
{
	int		written;
	int		placeholder;
	size_t	base_len;

	written = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		placeholder = safer_putnbr_ul_base(n / base_len, base);
		if (placeholder < 0)
			return (-1);
		written += placeholder;
	}
	if (safer_putchar(base[n % base_len]) < 0)
		return (-1);
	written++;
	return (written);
}
