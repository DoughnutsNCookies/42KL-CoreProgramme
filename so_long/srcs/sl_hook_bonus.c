/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:10:47 by schuah            #+#    #+#             */
/*   Updated: 2022/08/03 19:07:34 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

int	sl_exit(t_gm *gm)
{
	sl_freeeverything(gm);
	system("leaks so_long");
	exit(0);
}

int	sl_getinput(int keycode, t_gm *gm)
{
	mlx_clear_window(gm->mlx, gm->window.ref);
	if (keycode == KEY_ESC)
		sl_exit(gm);
	sl_movement(gm, keycode);
	sl_mapevents(gm);
	sl_putimage(gm);
	return (0);
}

int	sl_update(t_gm *gm)
{
	sl_playeranim(gm);
	return (0);
}

void	sl_hooks(t_gm *gm)
{
	mlx_hook(gm->window.ref, EXIT_EVENT, EXIT_MASK, &sl_exit, gm);
	mlx_key_hook(gm->window.ref, &sl_getinput, gm);
	mlx_loop_hook(gm->mlx, &sl_update, gm);
}
