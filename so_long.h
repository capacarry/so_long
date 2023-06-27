/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:29:43 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/27 16:10:23 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_ROWS 50
# define MAX_COLS 50

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	int		img_width;
	int		img_height;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct so_long
{	
	char 	*str_actions;
	int		map_fd;
	void 	*actions_img;
	int		nb_actions;
	int		rows;
	int		found_exit;
	int		enemies;
	int		cols;
	t_data	*data;
	t_vars	*vars;
	int		start[2];
	int		exit[2];
	int		collect;
	char	**map;
	void	*map_buffer;
}			t_so_long;

int			map_file_checker(char *map);
int			map_layout_checker(t_so_long *content, char *argv[]);
int			check_walls(t_so_long *content);
void		free_double_array(t_so_long *content);
int			check_map_size(t_so_long *content);
int			flood_fill(t_so_long *content);
char		*get_next_line(int fd);
void		delete_break(t_so_long *content);
void		free_mlx_stuff(t_so_long *content);
void		player_loop(t_so_long *content);
void		enemy_loop(t_so_long *content);
void		wall_loop(t_so_long *content);
int close_window(t_so_long *content);

#endif
