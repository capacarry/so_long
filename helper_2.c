/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:09:00 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/28 20:44:00 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keys(int key_code, t_so_long *content)
{
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
}

void	images_to_array_2(t_so_long *content, char element)
{
	if (element == '0')
		content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
				"./images/chao.xpm",
				&content->data->img_width,
				&content->data->img_height);
	else if (element == '1')
		wall_loop(content);
	else if (element == 'P')
		player_loop(content);
	else if (element == 'X')
		enemy_loop(content);
	else if (element == 'C')
		content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
				"./images/pessoa_viva.xpm",
				&content->data->img_width,
				&content->data->img_height);
}

void	image_to_window(t_so_long *content, int x, int y)
{
	mlx_put_image_to_window(content->vars->mlx, content->vars->win,
		content->data->img, y * 64, x * 64);
	if (content->str_actions != NULL)
		free(content->str_actions);
}
