/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:30:55 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/12 09:51:47 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		clean_exit(vars, err_msg("Can't start mlx", 1));
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!vars->win)
		clean_exit(vars, err_msg("Can't create mlx window", 1));
	return ;
}

int main(int ac, char **av)
{
    t_vars  vars;

    if (!parse_args(av, ac))
        return (1);
    init_data(&vars);
    if (parse_data(av[1], &vars) != 0)
        return (1);
    if (extract_map_info(&vars, vars.mapinfo.file) == FAILURE)
		return (free_vars(&vars), 1);
    if (!vars.map || !vars.map[0])
    {
        err_msg("Map is missing", FAILURE);
        return (free_vars(&vars), 1);
    }
    if (parsing_map(&vars, vars.map) == FAILURE)
        return (free_vars(&vars), 1);
    if (parsing_textures(&vars.texinfo) == FAILURE)
		return (free_vars(&vars), 1);
	init_mlx(&vars);
	mlx_key_hook(vars.win, key_press, &vars);
    mlx_hook(vars.win, 17, 0, close_window, &vars);
    mlx_loop(vars.mlx);
    return (0);
}
