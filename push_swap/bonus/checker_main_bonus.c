/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:25:50 by schuah            #+#    #+#             */
/*   Updated: 2022/07/29 16:22:05 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* Sets the default value / initializing values to the struct */
static void	default_flag_ps(t_psinfo *psinfo)
{
	psinfo->len_a = 0;
	psinfo->len_b = 0;
	psinfo->total_len = 0;
	psinfo->mp = 0;
	psinfo->stack_a = NULL;
	psinfo->stack_b = NULL;
}

int	main(int ac, char **av)
{
	t_psinfo	*psinfo;

	if (ac > 1)
	{
		psinfo = malloc(sizeof(t_psinfo));
		default_flag_ps(psinfo);
		get_data(psinfo, av);
		ps_printall(psinfo);
	}
	return (0);
}
