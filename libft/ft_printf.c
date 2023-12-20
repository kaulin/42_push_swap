/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:32:31 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/20 15:53:48 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(t_printer *printer)
{
	printer->source++;
	if (!ft_strchr("cspdiuxX%", *printer->source))
		return (1);
	if (*printer->source == 'c')
		printer->status = print_c(printer);
	if (*printer->source == 's')
		printer->status = print_s(printer);
	if (*printer->source == 'p')
		printer->status = print_p(printer);
	if (*printer->source == 'd' || *printer->source == 'i')
		printer->status = print_d(printer);
	if (*printer->source == 'u')
		printer->status = print_u(printer);
	if (*printer->source == 'x' || *printer->source == 'X')
		printer->status = print_x(printer);
	if (*printer->source == '%')
	{
		if (safer_putchar('%') < 0)
			printer->status = 1;
		else
			printer->status = 0;
		printer->output_count++;
	}
	printer->source++;
	return (printer->status);
}

int	ft_printf(const char *source, ...)
{
	t_printer	printer;

	if (!source)
		return (-1);
	printer.source = source;
	printer.output_count = 0;
	va_start(printer.params, source);
	while (*printer.source)
	{
		if (*printer.source != '%')
		{
			if (safer_putchar(*printer.source) < 0)
				return (-1);
			printer.source++;
			printer.output_count++;
		}
		else if (convert(&printer))
			return (-1);
	}
	va_end(printer.params);
	return (printer.output_count);
}
/*
You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/