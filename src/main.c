/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:30:55 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/04 14:22:36 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
    t_vars  vars;

    if (!parse_args(&vars, av, ac))
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
        //printf("height after extract_map_info = %d\n", vars.mapinfo.height);
        //printf("width after extract_map_info= %d\n", vars.mapinfo.width);
        if (parsing_map(&vars, vars.map) == FAILURE)
        return (free_vars(&vars), 1);
    return (0);
}