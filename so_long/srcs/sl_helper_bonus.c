/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_helper_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:34:02 by schuah            #+#    #+#             */
/*   Updated: 2022/08/03 17:16:05 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

void	sl_printply(t_gm *gm)
{
	ft_printf("------------------------------\n");
	ft_printf("Player Alive: %d\n", gm->player.alive);
	ft_printf("Player Pickups: %d\n", gm->player.pickups);
	ft_printf("Player Moves: %d\n", gm->player.moves);
	ft_printf("Player X: %d\tPlayer Y: %d\n", gm->player.pos.x, gm->player.pos.y);
	ft_printf("Map Xs: %d\tMap Ys: %d\n", gm->map.x, gm->map.y);
	ft_printf("N_Pickups: %d\n", gm->map.n_pick);
	ft_printf("------------------------------\n");
}

void	sl_printmap(t_gm *gm)
{	
	int	x;
	int	y;

	y = -1;
	while (gm->map.layout[++y] != 0)
	{
		x = -1;
		while (gm->map.layout[y][++x] != '\0')
			ft_printf("%c", gm->map.layout[y][x]);
		ft_printf("\n");
	}
}

void	sl_freeeverything(t_gm *gm)
{
	int	y;

	y = -1;
	return ;
	ft_printf("%c", gm->map.layout[0]);
	while (gm->map.layout[++y] != 0)
		free(gm->map.layout[y]);
	free(gm->map.layout);
}
