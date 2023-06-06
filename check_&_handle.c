/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_&_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:35:13 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/06 15:47:42 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_file_checker(int argc, char *map)
{
	int		i;
	char	*str;

	str = ".ber";
	i = 0;
	while (map[i] != '.')
	{
		i++;
	}
	if (map[i] == '\0')
		;
	{
		perror("Invalid Map Format, please enter a '.ber' file.\n");
		exit(1);
	}
	if (ft_strcmp(map + i, str) == 0)
		return (1);
	perror("Invalid Map Format, please enter a '.ber' file.\n");
	exit(1);
}

int	check_map_size(t_so_long *content)
{
	int line_size;
	int i;
	
	i = 0;
	line_size = ft_strlen(content->map[i]);
	while(content->map[i])
	{
		if(line_size != ft_strlen(content->map[i]))
		{	
			free_double_array(content);
			return(0);
		}
	}
	return(1);
}

int check_walls(t_so_long *content)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (content->map[0][j] != '\0')
	{
		if (content->map[0][j] != '1')
		{
			free_double_array(content);
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
				free_double_array(content);
				return (0);
			}
			i++;
		}
		else
		{
			free_double_array(content);
			return (0);
		}
	}
	j = 0;
	while (content->map[i - 1][j] != '\0')
	{
		if (content->map[1 - 1][j] != '1')
		{
			free_double_array(content);
			return (0);
		}
		j++;
	}
	return (1);
}

int check_elements(t_so_long *content)
{
	int i;
	int j;
	int start;
	int exit;
	int collect;

	i = 0;
	j = 0;
	while(content->map[i])
	{
		while(content->map[i][j])
		{	
			if(content->map[i][j] == 'P')
			{
				start += 1;
				content->start[0] = i;
				content->start[1] = j;	
			}
			else if(content->map[i][j] == 'E')
			{
				exit += 1;
				content->exit[0] = i;
				content->exit[1] = j;
			}	
			else if(content->map[i][j] == 'C')
				collect += 1;
			j++;
		}
		i++;
	}
	if(start == 1 && exit == 1 && collect != 0)
		return(1);
	free_double_array(content);
	return(0);
}

int	map_layout_checker(t_so_long *content)
{
	int i;

	i = 0;
	while (content->map[i] = get_next_line(content->map_fd))
	{
		i++;
	}
	if (!content->map)
	{
		free_double_array(content);
		return (0);
	}
	if (check_walls(content) && check_map_size(content)
		&& check_elements(content) && check_path(content))
		return (1);
	free_double_array(content);
	return (0);
}