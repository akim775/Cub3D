/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:43:16 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/04 15:57:58 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static	bool	error_surr(int y, int x)
{
	ft_putstr_fd(RED"Error : ", 2);
	ft_putstr_fd("Map is not surrounded at "BRED, 2);
	ft_putstr_fd("[", 2);
	ft_putnbr_fd(y, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd("[", 2);
	ft_putnbr_fd(x, 2);
	ft_putstr_fd("]\n"RESET, 2);
	return (false);
}

bool	is_map_closed(t_mapinfo *map, char **maps)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (y != map->height)
	{
		while (maps[y][i])
		{
			if (maps[y][i] == '0' || ft_isalpha(maps[y][i]))
			{
				if (maps[y][i + 1] != '0' && maps[y][i + 1] != '1' && !ft_isalpha(maps[y][i + 1]))
					return (error_surr(y, i + 1));
				if (maps[y][i - 1] != '0' && maps[y][i -1] != '1' && !ft_isalpha(maps[y][i -1]))
					return (error_surr(y, i - 1));
				if (maps[y + 1][i] != '0' && maps[y + 1][i] != '1' && !ft_isalpha(maps[y + 1][i]))
					return (error_surr(y + 1, i));
				if (maps[y - 1][i] != '0' && maps[y - 1][i] != '1' && !ft_isalpha(maps[y - 1][i]))
					return (error_surr(y - 1, i));
			}
			i++;
		}
		i = 0;
		y++;
	}
	return (true);
}

int	parsing_map(t_vars *vars, char **map_tab)
{
	if (!vars->map || !vars->map[0])
		return (err_msg("Missing map", FAILURE));
	if (!is_map_closed(&vars->mapinfo, map_tab))
		return (FAILURE);
	if (vars->mapinfo.height < 3)
		return (err_msg("To be valid, the map requires a minimum of 3 lines", FAILURE));
	if (!is_valid_char(vars, map_tab))
		return (FAILURE);
	if (is_player_position_valid(vars, map_tab) == FAILURE)
		return (FAILURE);
	/*if (check_map_is_at_the_end(&vars->mapinfo) == FAILURE)
		return (err_msg("Map is not at the end of the file", FAILURE));*/
	return (SUCCESS);
}
