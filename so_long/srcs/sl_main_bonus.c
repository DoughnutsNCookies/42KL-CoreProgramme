/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:19:20 by schuah            #+#    #+#             */
/*   Updated: 2022/08/03 17:25:28 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

/* Start of the main function */
int	main(int ac, char **av)
{
	t_gm	gm;

	if (sl_getmap(&gm, ac, av))
		return (0);
	gm.mlx = mlx_init();
	sl_newwindow(&gm, (gm.map.x * PLY_MVSPD),
		(gm.map.y * PLY_MVSPD), "so_long");
	sl_defaultplayer(&gm);
	sl_defaultmap(&gm);
	sl_putimage(&gm);
	sl_hooks(&gm);
	mlx_loop(gm.mlx);
	return (0);
}
