/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:47:20 by schuah            #+#    #+#             */
/*   Updated: 2022/07/07 19:29:15 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(char *str, int fd)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (str[count] != '\0')
	{
		ft_putchar_fd(*(str + count), fd);
		count++;
	}
	return (count);
}

int	ft_printpointer(unsigned long string_addr, int fd, int wc)
{
	if (wc == 0)
	{
		ft_putstr_fd("0x", fd);
		wc = 2;
	}
	if (string_addr >= 16)
	{
		wc = ft_printpointer(string_addr / 16, fd, wc);
		wc += ft_printpointer(string_addr % 16, fd, wc);
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[string_addr], fd);
		return (1);
	}
	return (wc);
}

int	ft_print_hex(unsigned int n, int fd, int wc, char c)
{
	if (n >= 16)
	{
		wc = ft_print_hex(n / 16, fd, wc, c);
		wc += ft_print_hex(n % 16, fd, wc, c);
	}
	else
	{
		if (c == 'x')
			ft_putchar_fd("0123456789abcdef"[n], fd);
		if (c == 'X')
			ft_putchar_fd("0123456789ABCDEF"[n], fd);
		return (1);
	}
	return (wc);
}

int	ft_printnumber(int n, int fd)
{
	int	wc;

	wc = 0;
	if (n < 0)
		return (ft_putnbr_fd(n, fd, wc) + 1);
	return (ft_putnbr_fd(n, fd, wc));
}

int	ft_printun(unsigned int n, int fd, int wc)
{
	if (n >= 10)
	{
		wc += ft_printun(n / 10, fd, wc);
		wc += ft_printun(n % 10, fd, wc);
	}
	else
	{
		write(fd, &"0123456789"[n], 1);
		return (1);
	}
	return (wc);
}
