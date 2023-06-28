/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:35:13 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/28 20:49:50 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_file_checker(char *map)
{
	char	*str;

	str = ".ber";
	if (map)
	{
		while (*map && *map != '.')
		{
			map++;
		}
		if (ft_strncmp(map, str, 5) == 0)
			return (1);
	}
	perror("Invalid File\n");
	exit(1);
}

int	check_map_size(t_so_long *content)
{
	int	line_size;
	int	i;

	i = 0;
	line_size = ft_strlen(content->map[i]);
	while (content->map[i])
	{
		if (line_size != ft_strlen(content->map[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(t_so_long *content)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (content->map[0][j] != '\0')
	{
		if (content->map[0][j] != '1')
			return (0);
		j++;
	}
	if (!check_walls_2(content, i, j))
		return (0);
	return (1);
}

int	check_elements(t_so_long *content)
{
	int	i;
	int	j;

	content->enemies = 0;
	content->collect = 0;
	content->single_start = 0;
	content->single_exit = 0;
	i = 0;
	while (content->map[i] != NULL)
	{
		j = 0;
		while (content->map[i][j] != '\0')
		{
			if (!check_elements_2(content, i, j))
				return (0);
			j++;
		}
		i++;
	}
	content->cols = j;
	if (content->single_start == 1 && content->single_exit == 1
		&& content->collect != 0)
		return (1);
	printf("Hello elements\n");
	return (0);
}

int	map_layout_checker(t_so_long *content, char *argv[])
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(content->map_fd);
	if (tmp == NULL)
		return (0);
	content->rows = 1;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(content->map_fd);
		content->rows++;
	}
	close(content->map_fd);
	initialize_map(content, i, argv);
	if (check_walls(content) && check_map_size(content)
		&& check_elements(content) && flood_fill(content))
		return (1);
	free_double_array(content);
	return (0);
}
