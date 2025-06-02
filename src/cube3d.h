/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:44:58 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/02 17:14:36 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
//# include "mlx.h"
# include <stddef.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include <stdint.h>

# define RED	"\033[0;31m"
# define BRED		"\033[1;31m"
# define RESET "\033[0m"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 600

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	int				floor_set;
	int				ceiling_set;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			last_line_map;
}	t_mapinfo;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_texinfo	texinfo;
	t_mapinfo	mapinfo;
	char		**map;
	int			**texture_pixels;
	int			**textures;
}   t_vars;

int		main(int ac, char **av);
int		extract_map_info(t_vars *vars, char **map);
int		fill_color_textures(t_vars *vars, t_texinfo *textures, char *line, int j);
int		err_msg(char *str, int code);
int		free_vars(t_vars *vars);
bool	parse_args(t_vars *vars, char **argv, int ac);
bool	check_file(char *file, t_vars *vars);
void	init_data(t_vars *vars);
void	parse_data(char *path, t_vars *vars);
void	*ft_calloc(size_t nmemb, size_t size);
void	free_tab(void **tab);
int		start_map_creation(t_vars *vars, char **file, int i);


#endif