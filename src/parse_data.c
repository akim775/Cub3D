/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:18:37 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/04 12:01:45 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*void	print_map(char **map)
{
	int	i = 0;

	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}*/

static int	count_lines(char *path)
{
	int		fd;
	char	*line = NULL;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		err_msg(strerror(errno), errno);
	else
	{
		//printf("[DEBUG] Ligne lue : [%s]\n", line);
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
    //printf("[DEBUG] Nombre de lignes dans le fichier : %d\n", line_count);
	return (line_count);
}

static void	fill_tab(int row, int column, int i, t_vars *vars)
{
	char	*line;

	line = get_next_line(vars->mapinfo.fd);
	while (line != NULL)
	{
		vars->mapinfo.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!vars->mapinfo.file[row])
		{
			err_msg("Malloc error", 0);
			return (free_tab((void **)vars->mapinfo.file));
		}
		while (line[i] != '\0')
			vars->mapinfo.file[row][column++] = line[i++];
		vars->mapinfo.file[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(vars->mapinfo.fd);
	}
	vars->mapinfo.file[row] = NULL;
}

int	parse_data(char *path, t_vars *vars)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	vars->mapinfo.line_count = count_lines(path);
	if (vars->mapinfo.line_count == 0)
		return (err_msg("Map file is empty", 1));
	vars->mapinfo.path = path;
	vars->mapinfo.file = ft_calloc(vars->mapinfo.line_count \
			+ 1, sizeof(char *));
	if (!(vars->mapinfo.file))
		return (err_msg("Malloc error", 1));
	vars->mapinfo.fd = open(path, O_RDONLY);
	if (vars->mapinfo.fd < 0)
		err_msg(strerror(errno), 1);
	else
	{
		fill_tab(row, column, i, vars);
		close(vars->mapinfo.fd);
		//print_map(vars->mapinfo.file);
	}
	return (0);
}
