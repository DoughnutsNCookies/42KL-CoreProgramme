/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:28:47 by schuah            #+#    #+#             */
/*   Updated: 2022/07/07 16:35:41 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n, int base)
{
	size_t		i;
	long long	an;
	char		*output;

	an = n;
	i = (n <= 0);
	while (n != 0 && ++i > 0)
		n = n / base;
	output = malloc(sizeof(char) * (i + 1));
	if (output == NULL)
		return (NULL);
	if (an < 0)
		output[0] = '-';
	if (an < 0)
		an *= -1;
	output[i--] = '\0';
	if (an == 0)
		output[0] = 48;
	while (i >= 0 && an)
	{
		output[i--] = (an % base) + '0';
		an /= base;
	}
	return (output);
}
