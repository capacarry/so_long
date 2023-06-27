/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:26:49 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/27 16:13:43 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_to_array(t_so_long *content, char element, int x, int y)
{	
	mlx_destroy_image(content->vars->mlx, content->data->img);
	if (element == '0')
		content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
				"./images/chao.xpm", &content->data->img_width,
				&content->data->img_height);
	else if (element == '1')
		wall_loop(content);
	else if (element == 'P')			
			player_loop(content);
	else if (element == 'X')
			enemy_loop(content);
	else if (element == 'C')
		content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
				"./images/pessoa_viva.xpm", &content->data->img_width,
				&content->data->img_height);
	else if (element == 'E')
	{	
		if(content->collect != 0)
		content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
				"./images/porta_fechada.xpm", &content->data->img_width,
				&content->data->img_height);
		else		
		content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
				"./images/porta_aberta.xpm", &content->data->img_width,
				&content->data->img_height);
	}
	else if (element == 'O')
			content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
				"./images/kill_c.xpm", &content->data->img_width,
				&content->data->img_height);
	content->str_actions = ft_itoa(content->nb_actions);
	mlx_string_put(content->vars->mlx,content->vars->win, content->cols ,content->rows ,0xFFFFFF,content->str_actions);
	mlx_put_image_to_window(content->vars->mlx,content->vars->win,content->data->img, y * 64,x * 64);
	if(content->str_actions != NULL)
		free(content->str_actions);
}

int	find_element(t_so_long *content)
{
	int	i;
	int	j;
	
	i = 0;
	usleep(50000);
	while (content->map[i])
	{
		j = 0;
		while (content->map[i][j])
		{
			images_to_array(content, content->map[i][j], i, j);
			j++;
		}
		i++;
	}
	return(0);
}

int	actions(int key_code, t_so_long *content)
{	
	int tmp[2];

	tmp[0] = content->start[0];
	tmp[1] = content->start[1];

	if(content->map[content->start[0]][content->start[1]] == '1')
		return(0);
	if (key_code == ESC)	
		close_window(content);
	else if (key_code == UP)
		content->start[0]--;
	else if (key_code == DOWN)
		content->start[0]++;
	else if (key_code == LEFT)
		content->start[1]--;
	else if (key_code == RIGHT)
		content->start[1]++;
	if(content->map[content->start[0]][content->start[1]] == 'C' )
	{	
		content->map[content->start[0]][content->start[1]] = 'O';
		write(1,"\nYOU HAVE CONSUMED A SOUL!\n",26);
		content->collect--;
	}
	if(content->map[content->start[0]][content->start[1]] == '1')
	{	
		content->start[0] = tmp[0];
		content->start[1] = tmp[1];
		return(0);
	}
	else if (content->map[content->start[0]][content->start[1]] == 'X')
	{	
		write(1, "\n\033[31mYou Lose!\033[0m", 20);	
		close_window(content);
	}
	if(content->map[content->start[0]][content->start[1]] == 'E' && content->collect > 0)
	{	
		content->start[0] = tmp[0];
		content->start[1] = tmp[1];
		return(0);
	}
	else if (content->map[content->start[0]][content->start[1]] == 'E' && content->collect == 0)
	{	
		write(1, "\n\033[32mYou Won!\033[0m\n", 20);
		close_window(content);
	}
	content->nb_actions += 1;
	if(content->map[content->start[0]][content->start[1]] != 'O')
		content->map[content->start[0]][content->start[1]] = 'P';
	if (content->start[0] != tmp[0] || content->start[1] != tmp[1])
		content->map[tmp[0]][tmp[1]] = '0';
	return (0);
}

void	start_mlx(t_so_long *content)
{
	content->vars = malloc(sizeof(t_vars));
	content->vars->mlx = mlx_init();
	content->vars->win = mlx_new_window(content->vars->mlx, content->cols * 64,
			(content->rows - 1)  * 64, "./so_long");
	mlx_key_hook(content->vars->win, actions, content);
	mlx_hook(content->vars->win, 17, 0L, close_window, content);
	content->data = malloc(sizeof(t_data));
	content->data->img = mlx_new_image(content->vars->mlx, 64, 64);
	mlx_loop_hook(content->vars->mlx,find_element,content);
	mlx_loop(content->vars->mlx);
}

int	main(int argc, char *argv[])
{
	t_so_long content;

	if (argc != 2)
	{
		perror("Wrong Number of arguments\n");
		exit(1);
	}
	if (map_file_checker(argv[1]))
	{
		if ((content.map_fd = open(argv[1], O_RDONLY)) == -1)
		{
			perror("Failure opening file");
			exit(1);
		}
		if (!map_layout_checker(&content, argv))
		{
			close(content.map_fd);
			perror("This Map isn't valid acording to game rules and/or formating.\n");
			exit(1);
		}
	}
	write(1, "\033[32mSTARTING GAME!\033[0m\n", 24);
	content.nb_actions = 0;
	start_mlx(&content);
}