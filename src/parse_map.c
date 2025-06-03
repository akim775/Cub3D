/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:43:16 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/03 14:51:37 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	bool	error_surr(int y, int x)
{
	ft_putstr_fd(RED"Error\n", 2);
	ft_putstr_fd("Map is not surrounded at "BRED, 2);
	ft_putstr_fd("[", 2);
	ft_putnbr_fd(y, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd("[", 2);
	ft_putnbr_fd(x, 2);
	ft_putstr_fd("]\n"RESET, 2);
	return (false);
}
static bool	is_wall(int x, int y, t_mapinfo *map, char **maps)
{
	if (y - 1 >= 0)
	{
		if (maps[y - 1][x] == ' ')
			return (true);
	}
	if (y + 1 < map->height)
	{
		if (maps[y + 1][x] == ' ')
			return (true);
	}
	if (x + 1 < (int)ft_strlen(maps[y]))
	{
		if (maps[y][x + 1] == ' ')
			return (true);
	}
	if (x - 1 >= 0)
	{
		if (maps[y][x - 1] == ' ')
			return (true);
	}
	return (false);
}

static	bool	is_map_border(int x, int y, t_mapinfo *map, char **maps)
{
	if (maps[y][x] == ' ')
		return (false);
	if (x <= 0 || x >= (int)ft_strlen(maps[y]) - 1
		|| y <= 0 || y >= map->height - 1)
		return (true);
	return (is_wall(x, y, map, maps));
}

bool	is_map_closed(t_mapinfo *map, char **maps)
{
	int	x;
	int	y;

	y = 0;
	while (maps[y])
	{
		x = 0;
		while (maps[y][x])
		{
			if (is_map_border(x, y, map, maps) && maps[y][x] != '1')
				return (error_surr(y, x));
			++x;
		}
		++y;
	}
	return (true);
}

int	parsing_map(t_vars *vars, char **map_tab)
{
	if (!vars->map)
		return (err_msg("Missing map", FAILURE));
	if (is_map_closed(&vars->mapinfo, map_tab) == FAILURE)
		return (err_msg("Map is not closed", FAILURE));
	if (vars->mapinfo.height < 3)
		return (err_msg("To be valid, the map requires a minimum of 3 lines", FAILURE));
	if (check_map_elements(vars, map_tab) == FAILURE)
		return (FAILURE);
	if (check_player_position(vars, map_tab) == FAILURE)
		return (FAILURE);
	if (check_map_is_at_the_end(&vars->mapinfo) == FAILURE)
		return (err_msg(vars->mapinfo.path, ERR_MAP_LAST, FAILURE));
	return (SUCCESS);
}
