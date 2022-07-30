/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_getters2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:18:58 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 13:51:34 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* Prints all data needed for debugging */
void	ps_printall(t_psinfo *psinfo)
{
	int	i;

	i = 0;
	ft_printf("\n|MP: %d|\n", psinfo->mp);
	ft_printf("|Len A: %d | Len B: %d|\n", psinfo->len_a, psinfo->len_b);
	while (i < psinfo->len_a || i < psinfo->len_b)
	{
		if (psinfo->stack_a[i] != 0)
			ft_printf("Stack A[%d]: %d\t\t\t\t", i, psinfo->stack_a[i]);
		else if (psinfo->stack_a[i] == 0 && i < psinfo->len_a)
			ft_printf("Stack A[%d]: %d\t\t\t\t", i, psinfo->stack_a[i]);
		else
			ft_printf("\t\t\t\t\t");
		if (i < psinfo->len_b)
			ft_printf("Stack B[%d]: %d", i, psinfo->stack_b[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

/* Creates a copy of a stack*/
int	*get_stack(t_psinfo *psinfo, char c)
{
	int	i;
	int	*output;

	if (c == 'a')
	{
		output = malloc(sizeof(int) * psinfo->len_a);
		if (output == NULL)
			return (NULL);
		i = -1;
		while (++i < psinfo->len_a)
			output[i] = psinfo->stack_a[i];
		return (output);
	}
	output = malloc(sizeof(int) * psinfo->len_b);
	if (output == NULL)
		return (NULL);
	i = -1;
	while (++i < psinfo->len_b)
		output[i] = psinfo->stack_b[i];
	return (output);
}

/* Returns errno if there are any error present, 0 if none */
int	get_error(t_psinfo *psinfo, char *str, int j)
{
	int	i;

	i = -1;
	if (str[0] == '\0')
		return (1);
	while (str[++i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (str[i] == '-' && ft_isdigit(str[i + 1]) && str[i - 1] == '\0')
				continue ;
			return (1);
		}
	}
	if (ft_atoi(str) < -2147483648)
		return (2);
	if (ft_atoi(str) > 2147483647)
		return (3);
	i = -1;
	while (++i < j)
		if (psinfo->stack_a[i] == ft_atoi(str))
			return (4);
	return (0);
}

/* Checks whether the array is sorted */
int	is_sorted(int *array, int len)
{
	int	i;

	i = 0;
	while (++i < len)
	{
		if (array[i - 1] > array[i])
			return (0);
	}
	return (1);
}
