/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getters2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:49:39 by schuah            #+#    #+#             */
/*   Updated: 2022/07/29 12:43:00 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

/* Converts the input numbers into index form */
void	get_converted_stack(t_psinfo *psinfo)
{
	int	*sorted_tmp;
	int	len;
	int	i;
	int	j;

	sorted_tmp = get_stack(psinfo, 'a');
	quicksort(sorted_tmp, 0, psinfo->len_a - 1);
	len = psinfo->len_a;
	i = 0;
	j = 0;
	while (len > 0)
	{
		if (psinfo->stack_a[i] == sorted_tmp[j])
		{
			psinfo->stack_a[i] = j;
			i++;
			len--;
			j = -1;
		}
		j++;
	}
	free(sorted_tmp);
}

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

/* Returns errno if there are any error present, 0 if none */
int	get_error(t_psinfo *psinfo, char *str, int j)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (ft_isdigit(str[i]) == 0 && (str[i] != '-'))
			return (1);
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
