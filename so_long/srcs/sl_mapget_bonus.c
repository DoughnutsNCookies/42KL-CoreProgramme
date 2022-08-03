/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mapget_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:28:56 by schuah            #+#    #+#             */
/*   Updated: 2022/08/03 15:00:07 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

static int	sl_checkfileformat(int ac, char **av)
{
	int		i;
	int		wc;
	int		errno;
	char	**input;

	if (ac < 2)
		return (ft_printf("Error\nNo file input\n"));
	i = 0;
	errno = 0;
	while (++i < ac)
	{
		wc = ft_getwc(av[i], '.');
		input = ft_split(av[i], '.');
		if (ft_strncmp(input[wc - 1], "ber", 4) != 0 && errno == 0)
			errno = 1;
	}
	i = -1;
	while (++i < wc)
		free(input[i]);
	free(input);
	if (errno == 1)
		return (ft_printf("Error\nInvalid file format\n"));
	return (0);
}

static int	sl_checkmapcontent(t_gm *gm, char *str, int line)
{
	int	i;

	i = -1;
	while (str[++i] != '\0' && str[i] != '\n')
	{
		if (str[i] != '1' && (line == 0 || line == -1))
			return (1);
		if (i == 0 && str[i] != '1')
			return (1);
	}
	if (str[i] == '\n' && line == -1)
		return (1);
	if (gm->map.x == 0)
		gm->map.x = i;
	if (i != gm->map.x)
		return (1);
	i--;
	if (str[i] != '1')
		return (1);
	return (0);
}

static int	sl_checkmapformat(t_gm *gm, int ac, char **av)
{
	int		fd;
	int		line;
	char	*str;
	char	*prev;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nCannot open file\n"));
	str = get_next_line(fd);
	prev = str;
	line = 0;
	gm->map.x = 0;
	while (str != NULL)
	{
		if (sl_checkmapcontent(gm, str, line++))
		{
			free(str);
			close(fd);
			return (ft_printf("Error\nInvalid map template\n"));
		}
		gm->map.y++;
		str = get_next_line(fd);
		if (str == NULL && sl_checkmapcontent(gm, prev, -1))
		{
			free(prev);
			close(fd);
			return (ft_printf("Error\nInvalid map template\n"));
		}
		free(prev);
		prev = str;
	}
	close(fd);
	return (0);
}

static int	sl_setmap(t_gm *gm, int ac, char **av)
{
	int		fd;
	int		x;
	int		y;
	char	*str;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nCannot open file\n"));
	str = get_next_line(fd);
	gm->map.layout = malloc(sizeof(char *) * gm->map.y + 1);
	y = 0;
	while (str != NULL)
	{
		x = -1;
		gm->map.layout[y] = malloc(sizeof(char) * gm->map.x + 1);
		while (str[++x] != '\0' && str[x] != '\n')
			gm->map.layout[y][x] = str[x];
		gm->map.layout[y][x] = '\0';
		y++;
		free(str);
		str = get_next_line(fd);
	}
	gm->map.layout[y] = 0;
	return (0);
}

int	sl_getmap(t_gm *gm, int ac, char **av)
{
	if (sl_checkfileformat(ac, av))
		return (1);
	if (sl_checkmapformat(gm, ac, av))
		return (1);
	if (sl_setmap(gm, ac, av))
		return (1);
	return (0);
}
