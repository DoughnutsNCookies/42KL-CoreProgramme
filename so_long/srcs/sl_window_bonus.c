/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:30:58 by schuah            #+#    #+#             */
/*   Updated: 2022/08/03 14:55:58 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

void	sl_newwindow(t_gm *gm, int height, int width, char *name)
{
	gm->window.ref = mlx_new_window(gm->mlx, height, width, name);
	gm->window.frame = 0;
	gm->window.size.x = height;
	gm->window.size.y = width;
}
