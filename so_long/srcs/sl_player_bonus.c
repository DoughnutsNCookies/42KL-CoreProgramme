/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:26:22 by schuah            #+#    #+#             */
/*   Updated: 2022/08/03 19:06:18 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

void	sl_defaultplayer(t_gm *gm)
{
	gm->player.alive = 0;
	gm->player.pickups = 0;
	gm->player.moves = 0;
	gm->player.image.ref = mlx_xpm_file_to_image(gm->mlx, "sprites/p.xpm",
			&gm->player.image.size.x, &gm->player.image.size.y);
}

void	sl_playeranim(t_gm *gm)
{
	gm->window.frame++;
	if (gm->window.frame == FPS)
		gm->player.pos.y += 1;
	else if (gm->window.frame >= FPS * 2)
	{
		gm->player.pos.y -= 1;
		gm->window.frame = 0;
	}
	mlx_put_image_to_window(gm->mlx, gm->window.ref,
		gm->player.image.ref, gm->player.pos.x, gm->player.pos.y);
}

void	sl_movement(t_gm *gm, int keycode)
{
	if (keycode == KEY_W && (gm->map.layout[(gm->player.pos.y / PLY_MVSPD) - 1]
			[gm->player.pos.x / PLY_MVSPD] != '1'))
	{
		gm->player.pos.y -= PLY_MVSPD;
		gm->player.moves++;
	}
	if (keycode == KEY_A && (gm->map.layout[(gm->player.pos.y / PLY_MVSPD)]
			[(gm->player.pos.x / PLY_MVSPD) - 1] != '1'))
	{
		gm->player.pos.x -= PLY_MVSPD;
		gm->player.moves++;
	}
	if (keycode == KEY_S && (gm->map.layout[(gm->player.pos.y / PLY_MVSPD) + 1]
			[gm->player.pos.x / PLY_MVSPD] != '1'))
	{
		gm->player.pos.y += PLY_MVSPD;
		gm->player.moves++;
	}
	if (keycode == KEY_D && (gm->map.layout[(gm->player.pos.y / PLY_MVSPD)]
			[(gm->player.pos.x / PLY_MVSPD) + 1] != '1'))
	{
		gm->player.pos.x += PLY_MVSPD;
		gm->player.moves++;
	}
}

void	sl_mapevents(t_gm *gm)
{
	if (gm->map.layout[gm->player.pos.y / PLY_MVSPD][gm->player.pos.x
		/ PLY_MVSPD] == 'C')
	{
		gm->map.layout[gm->player.pos.y / PLY_MVSPD][gm->player.pos.x
			/ PLY_MVSPD] = '0';
		gm->player.pickups++;
	}
	if (gm->map.layout[gm->player.pos.y / PLY_MVSPD][gm->player.pos.x
		/ PLY_MVSPD] == 'E' && gm->player.pickups == gm->map.n_pick)
	{
		sl_exit(gm);
	}
	sl_printply(gm);
}
