/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:18:02 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/12 09:52:06 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_vars *vars)
{
	(void)vars;
	if (key == 65307)
    {
        ft_putstr_fd("Game closed. See you next time!\n", 2);
		clean_exit(vars, 0);
    }
    return (0);
}

int	close_window(t_vars *vars)
{
	ft_putstr_fd("Game closed. See you next time!\n", 2);
	clean_exit(vars, 0);
	return (0);
}
