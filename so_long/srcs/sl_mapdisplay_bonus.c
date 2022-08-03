/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mapdisplay_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:38:05 by schuah            #+#    #+#             */
/*   Updated: 2022/08/03 19:01:56 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

void	sl_putimage(t_gm *gm)
{
	sl_displaymap(gm);
	mlx_put_image_to_window(gm->mlx, gm->window.ref,
		gm->player.image.ref, gm->player.pos.x, gm->player.pos.y);
}

void	sl_defaultmap(t_gm *gm)
{
	gm->map.pickup_img.ref = mlx_xpm_file_to_image(gm->mlx, "sprites/c.xpm",
			&gm->map.pickup_img.size.x, &gm->map.pickup_img.size.y);
	gm->map.wall_img.ref = mlx_xpm_file_to_image(gm->mlx, "sprites/1.xpm",
			&gm->map.wall_img.size.x, &gm->map.wall_img.size.y);
	gm->map.exit_img.ref = mlx_xpm_file_to_image(gm->mlx, "sprites/e.xpm",
			&gm->map.exit_img.size.x, &gm->map.exit_img.size.y);
	gm->map.spc_img.ref = mlx_xpm_file_to_image(gm->mlx, "sprites/0.xpm",
			&gm->map.spc_img.size.x, &gm->map.spc_img.size.y);
}

void	sl_displaymap(t_gm *gm)
{
	int	x;
	int	y;
	int	n_pick;

	y = -1;
	n_pick = 0;
	while (gm->map.layout[++y] != 0)
	{
		x = -1;
		while (gm->map.layout[y][++x] != 0)
		{
			mlx_put_image_to_window(gm->mlx, gm->window.ref,
				gm->map.spc_img.ref, (x * PLY_MVSPD), (y * PLY_MVSPD));
			if (gm->map.layout[y][x] == '1')
				mlx_put_image_to_window(gm->mlx, gm->window.ref,
					gm->map.wall_img.ref, (x * PLY_MVSPD), (y * PLY_MVSPD));
			if (gm->map.layout[y][x] == 'C')
			{
				mlx_put_image_to_window(gm->mlx, gm->window.ref,
					gm->map.pickup_img.ref, (x * PLY_MVSPD), (y * PLY_MVSPD));
				n_pick++;
			}
			if (gm->map.layout[y][x] == 'E')
				mlx_put_image_to_window(gm->mlx, gm->window.ref,
					gm->map.exit_img.ref, (x * PLY_MVSPD), (y * PLY_MVSPD));
			if (gm->map.layout[y][x] == 'P' && gm->player.alive == 0)
			{
				gm->player.pos.x = x * PLY_MVSPD;
				gm->player.pos.y = y * PLY_MVSPD;
				gm->player.alive = 1;
			}
		}
	}
	if (gm->map.n_pick <= 0)
		gm->map.n_pick = n_pick;
}
