/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:35:13 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/22 18:13:26 by gcapa-pe         ###   ########.fr       */
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
		{
			return (0);
		}
		j++;
	}
	while (content->map[i])
	{
		j = 0;
		if (content->map[i][j] == '1')
		{
			while (content->map[i][j] != '\0')
			{
				j++;
			}
			if (content->map[i][j - 1] != '1')
			{
				return (0);
			}
		}
		else
		{
			return (0);
		}
		i++;
	}
	j = 0;
	while (content->map[i - 1][j] != '\0')
	{
		if (content->map[1 - 1][j] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_elements(t_so_long *content)
{
	int	i;
	int	j;
	int	start;
	int	exit;

	content->enemies = 0;
	content->collect = 0;
	start = 0;
	exit = 0;
	i = 0;
	while (content->map[i] != NULL)
	{
		j = 0;
		while (content->map[i][j] != '\0')
		{
			if (content->map[i][j] == 'P')
			{
				start += 1;
				content->start[0] = i;
				content->start[1] = j;
			}
			else if (content->map[i][j] == 'E')
			{
				exit += 1;
				content->exit[0] = i;
				content->exit[1] = j;
			}
			else if (content->map[i][j] == 'C')
				content->collect += 1;
			else if (content->map[i][j] == 'X')
				content->enemies += 1;
			if (content->map[i][j] != '0' && content->map[i][j] != '1'
				&& content->map[i][j] != 'P' &&
				content->map[i][j] != 'E' && content->map[i][j] != 'C'
					&& content->map[i][j] != 'X')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	content->cols = j;
	if (start == 1 && exit == 1 && content->collect != 0)
		return (1);
	return (0);
}

int	map_layout_checker(t_so_long *content, char *argv[])
{
	int i;
	char *tmp;

	i = 0;
	tmp = get_next_line(content->map_fd);
	content->rows = 1;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(content->map_fd);
		content->rows++;
	}
	close(content->map_fd);
	content->map_fd = open(argv[1], O_RDONLY);
	content->map = malloc(sizeof(char *) * content->rows);
	content->map[i] = get_next_line(content->map_fd);
	while ((content->map[i] != NULL))
	{
		i++;
		content->map[i] = get_next_line(content->map_fd);
	}
	delete_break(content);
	if (check_walls(content) && check_map_size(content)
		&& check_elements(content) && flood_fill(content))
		return (1);
	free_double_array(content);
	return (0);
}