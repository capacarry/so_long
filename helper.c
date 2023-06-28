/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:22:24 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/28 20:21:00 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls_2(t_so_long *content, int i, int j)
{
	while (content->map[i])
	{
		j = 0;
		if (content->map[i][j] == '1')
		{
			while (content->map[i][j] != '\0')
				j++;
			if (content->map[i][j - 1] != '1')
				return (0);
		}
		else
			return (0);
		i++;
	}
	j = 0;
	while (content->map[i - 1][j] != '\0')
	{
		if (content->map[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_elements_2(t_so_long *content, int i, int j)
{
	if (content->map[i][j] == 'P')
	{
		content->single_start += 1;
		content->start[0] = i;
		content->start[1] = j;
	}
	else if (content->map[i][j] == 'E')
	{
		content->single_exit += 1;
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
	return (1);
}

void	initialize_map(t_so_long *content, int i, char *argv[])
{
	content->map_fd = open(argv[1], O_RDONLY);
	content->map = malloc(sizeof(char *) * content->rows);
	content->map[i] = get_next_line(content->map_fd);
	while ((content->map[i] != NULL))
	{
		i++;
		content->map[i] = get_next_line(content->map_fd);
	}
	delete_break(content);
}

int	actions_2(t_so_long *content, int tmp[])
{
	if (content->map[content->start[0]][content->start[1]] == '1'
		|| (content->map[content->start[0]][content->start[1]] == 'E'
		&& content->collect > 0))
	{
		content->start[0] = tmp[0];
		content->start[1] = tmp[1];
		return (0);
	}
	else if (content->map[content->start[0]][content->start[1]] == 'X')
	{
		write(1, "\n\033[31mYou Lose!\033[0m", 20);
		close_window(content);
	}
	else if (content->map[content->start[0]][content->start[1]] == 'E'
			&& content->collect == 0)
	{
		write(1, "\n\033[32mYou Won!\033[0m\n", 20);
		close_window(content);
	}
	content->nb_actions += 1;
	return (0);
}

int	actions_3(t_so_long *content, int tmp[])
{
	if (content->map[content->start[0]][content->start[1]] != 'O')
		content->map[content->start[0]][content->start[1]] = 'P';
	if (content->start[0] != tmp[0] || content->start[1] != tmp[1])
		content->map[tmp[0]][tmp[1]] = '0';
	return (0);
	if (content->map[content->start[0]][content->start[1]] == 'C')
	{
		content->map[content->start[0]][content->start[1]] = 'O';
		write(1, "\nYOU HAVE CONSUMED A SOUL!\n", 26);
		content->collect--;
	}
	return (0);
}
