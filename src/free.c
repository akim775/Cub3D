/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:12:07 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/09 12:55:14 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

int	free_vars(t_vars *vars)
{
	if (vars->textures)
		free_tab((void **)vars->textures);
	if (vars->texture_pixels)
		free_tab((void **)vars->texture_pixels);
	//free_texinfo(&vars->texinfo);
	//free_map(vars);
	return (FAILURE);
}

void	clean_exit(t_vars *vars, int code)
{
	if (!vars)
		exit(code);
	if (vars->win && vars->mlx)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		mlx_loop_end(vars->mlx);
		free(vars->mlx);
	}
	free_vars(vars);
	exit(code);
}
