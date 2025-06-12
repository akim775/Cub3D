/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:44:58 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/12 09:52:38 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../mlx/mlx.h"
# include <stddef.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>
# include <X11/X.h>
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
	unsigned long	floor_hex;
	unsigned long	ceiling_hex;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

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
	t_player	player;
	char		**map;
	int			**texture_pixels;
	int			**textures;
}   t_vars;

int		main(int ac, char **av);
int		extract_map_info(t_vars *vars, char **map);
int		fill_color_textures(t_texinfo *textures, char *line, int j);
int		err_msg(char *str, int code);
int		free_vars(t_vars *vars);
bool	parse_args(char **argv, int ac);
bool	check_file(char *fill);
void	init_data(t_vars *vars);
int		parse_data(char *path, t_vars *vars);
void	*ft_calloc(size_t nmemb, size_t size);
void	free_tab(void **tab);
int		start_map_creation(t_vars *vars, char **file, int i);
int		parsing_map(t_vars *vars, char **map_tab);
bool	is_valid_char(t_vars *vars, char **map_tab);
int		is_there_a_player(t_vars *vars, char **map_tab);
int		parsing_textures(t_texinfo *textures);
void	clean_exit(t_vars *vars, int code);
int		key_press(int key, t_vars *vars);
int		close_window(t_vars *vars);

#endif