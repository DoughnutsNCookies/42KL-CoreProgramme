/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:48:56 by schuah            #+#    #+#             */
/*   Updated: 2022/07/07 19:24:12 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int	ft_printf(const char *, ...);
int	ft_printchar(int c, int fd);
int	ft_printstring(char *str, int fd);
int	ft_printpointer(unsigned long string_addr, int fd, int wc);
int	ft_print_hex(unsigned int n, int fd, int wc, char c);
int	ft_printnumber(int n, int fd);
int	ft_printun(unsigned int n, int fd, int wc);

#endif
