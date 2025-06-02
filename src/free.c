/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:12:07 by ahamini           #+#    #+#             */
/*   Updated: 2025/05/23 13:15:38 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
