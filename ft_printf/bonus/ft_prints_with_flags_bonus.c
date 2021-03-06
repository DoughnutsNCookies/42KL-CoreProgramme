/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_with_flags_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:26:33 by schuah            #+#    #+#             */
/*   Updated: 2022/07/15 11:21:46 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_dupe(char c, int count)
{
	int	len;

	len = 0;
	while (count > 0)
	{
		ft_putchar_fd(c, 1);
		count--;
		len++;
	}
	return (len);
}

void	print_with_flag(char *str, t_flags *flags, int *wc)
{
	if (flags->dot == 1 && (flags->prec <= flags->width))
		*wc += print_dupe(flags->d, flags->width - flags->prec);
	else
		*wc += print_dupe(flags->d, flags->width - (int)ft_strlen(str));
}

void	print_sf(char *str, t_flags *flags, int *wc)
{
	int	i;

	if (str == NULL)
		print_sf("(null)", flags, wc);
	else
	{
		if (flags->neg == 0)
			print_with_flag(str, flags, wc);
		i = 0;
		while (i < (int)ft_strlen(str))
		{
			if (flags->dot == 1 && i >= flags->prec)
				break ;
			ft_putchar_fd(str[i++], 1);
			(*wc)++;
		}
		if (flags->neg == 1)
			print_with_flag(str, flags, wc);
	}
}

void	print_cf(char c, t_flags *flags, int *wc)
{
	if (flags->neg == 0)
		print_dupe(flags->d, flags->width - 1);
	ft_putchar_fd(c, 1);
	if (flags->neg == 1)
		print_dupe(flags->d, flags->width - 1);
	if (flags->width > 0)
		*wc += flags->width;
	else
		(*wc)++;
}
