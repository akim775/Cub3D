/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:12:14 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/02 15:46:56 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

size_t	calc_map_width(char **file, int start_index)
{
	int		i;
	size_t	max_len;
	size_t	current_len;

	i = start_index;
	max_len = 0;
	while (file[i])
	{
		current_len = ft_strlen(file[i]);
		if (max_len < current_len)
			max_len = current_len;
		i++;
	}
	return (max_len);
}

static int	calc_map_height(t_vars *vars, char **file, int start_index)
{
	int	i;
	int	j;
	int	height;

	i = start_index;
	height = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] && ft_isspace(file[i][j]))
			j++;
		if (file[i][j] != '1')
			break;
		height++;
		i++;
	}
	vars->mapinfo.last_line_map = i;
	return (height);
}

int	start_map_creation(t_vars *vars, char **file, int i)
{
    vars->mapinfo.height = calc_map_height(vars, file, i);
    vars->mapinfo.width = calc_map_width(file, i);
	vars->map = malloc(sizeof(char *) * (vars->mapinfo.height + 1));
	if (!vars->map)
		return (err_msg("Malloc error", FAILURE));
    if (create_map_array(&vars->mapinfo, vars->map, i) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}