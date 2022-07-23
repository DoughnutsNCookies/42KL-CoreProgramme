/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:02:20 by schuah            #+#    #+#             */
/*   Updated: 2022/07/07 10:29:15 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getwc(char const *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != '\0' && str[i] != c)
			i++;
		count++;
	}
	return (count);
}

char	*ft_strndup(char *str, size_t n)
{
	size_t	i;
	char	*output;

	output = malloc(sizeof(char) * n + 1);
	if (output == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
		output[i] = str[i];
	output[i] = '\0';
	return (output);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	*wordstart;
	char	**output;

	if (!s)
		return (NULL);
	count = ft_getwc(s, c);
	output = malloc(sizeof(char *) * count + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		wordstart = (char *)s;
		while (*s != '\0' && *s != c)
			s++;
		output[i++] = ft_strndup(wordstart, s - wordstart);
	}
	output[i] = 0;
	return (output);
}
