/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:30:55 by ahamini           #+#    #+#             */
/*   Updated: 2025/05/26 13:42:23 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
    t_vars  vars;

    if (!parse_args(&vars, av, ac))
        return (1);
    init_data(&vars);
    parse_data(av[1], &vars);
    if (extract_map_info(&vars, vars.mapinfo.file) == FAILURE)
		  return (free_vars(&vars), 1);
    return (0);
}