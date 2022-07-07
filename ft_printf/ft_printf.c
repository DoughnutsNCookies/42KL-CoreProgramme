/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:22:30 by schuah            #+#    #+#             */
/*   Updated: 2022/07/07 19:35:10 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(va_list args, const char *str, int index, int wc)
{
	while (str[++index] != '\0')
	{
		if (str[index] == '%' && str[index + 1] == 'c' && ++index > 0)
			wc += ft_putchar_fd(va_arg(args, int), 1) - 1;
		else if (str[index] == '%' && str[index + 1] == 's' && ++index > 0)
			wc += ft_printstring(va_arg(args, char *), 1) - 1;
		else if (str[index] == '%' && str[index + 1] == 'p' && ++index > 0)
			wc += ft_printpointer(va_arg(args, unsigned long), 1, 0) + 1;
		else if (str[index] == '%' && (str[index + 1] == 'd'
				|| str[index + 1] == 'i') && ++index > 0)
			wc += ft_printnumber(va_arg(args, int), 1) -1;
		else if (str[index] == '%' && str[index + 1] == 'u' && ++index > 0)
			wc += ft_printun(va_arg(args, unsigned int), 1, 0) - 1;
		else if (str[index] == '%' && (str[index + 1] == 'x'
				|| str[index + 1] == 'X') && ++index > 0)
			wc += ft_print_hex(va_arg(args, unsigned int), 1, 0, str[index]) - 1;
		else if (str[index] == '%' && str[index + 1] == '%' && ++index > 0)
			wc += ft_putchar_fd('%', 1) - 1;
		else
			ft_putchar_fd(str[index], 1);
		wc++;
	}
	return (wc);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		wc;

	va_start(args, str);
	wc = ft_print(args, str, -1, 0);
	va_end(args);
	return (wc);
}
