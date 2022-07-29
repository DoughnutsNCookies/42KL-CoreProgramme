/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:26:17 by schuah            #+#    #+#             */
/*   Updated: 2022/07/29 16:29:21 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/srcs/libft.h"
# include "../libft/srcs/ft_printf.h"
# include "../libft/srcs/get_next_line.h"

typedef struct s_psinfo
{
	int	len_a;
	int	len_b;
	int	total_len;
	int	mp;
	int	*stack_a;
	int	*stack_b;
}	t_psinfo;

/* Getter functions */
int		get_data(t_psinfo *psinfo, char **av);
int		*get_stack(t_psinfo *psinfo, char c);
int		get_error(t_psinfo *psinfo, char *str, int j);

/* Quick sort function to sort an array */
void	quicksort(int *array, int low, int high);
int		is_sorted(int *array, int len);

/* Helper functions */
void	ps_printall(t_psinfo *psinfo);

#endif