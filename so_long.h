/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:29:43 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/06 15:46:07 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct so_long
{
	int		map_fd;
	int     start[1];
	int		exit[1];
	char	**map;
}			t_so_long;

int			map_file_checker(int argc, char *map);
int			map_layout_checker(t_so_long *content);
int			check_walls(t_so_long *content);
void		free_double_array(t_so_long *content);
int			check_map_size(t_so_long *content);

#endif
