/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:22:30 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/28 16:44:24 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_so_long *content)
{
	free_double_array(content);
	mlx_destroy_window(content->vars->mlx, content->vars->win);
	mlx_destroy_image(content->vars->mlx, content->data->img);
	mlx_loop_end(content->vars->mlx);
	mlx_destroy_display(content->vars->mlx);
	free(content->vars->mlx);
	free(content->vars);
	free(content->data);
	exit(0);
}
