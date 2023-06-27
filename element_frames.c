/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_frames.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:39:05 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/23 16:16:01 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void enemy_loop(t_so_long *content)
{
	static int i = 0;
    char *img_fr[5];
	int num_frames;
	int frame_index;
	
	frame_index = 0;
	num_frames = 4;
    img_fr[0] = "images/priest_1.xpm";
    img_fr[1] = "images/priest_2.xpm";
    img_fr[2] = "images/priest_3.xpm";
    img_fr[3] = "images/priest_4.xpm";
    img_fr[4] = "images/priest_3.xpm";



    frame_index = i / (content->enemies + 1) % num_frames;
   
    content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
                                               img_fr[frame_index],
                                               &content->data->img_width,
                                               &content->data->img_height);
    i++;
}

void player_loop(t_so_long *content)
{	
	static int frames = 3;
	char *img_fr[5];
	
	img_fr[0] =  "images/polvo_1.xpm";
	img_fr[1] =  "images/polvo_2.xpm";
	img_fr[2] =  "images/polvo_3.xpm";
	img_fr[3] =  "images/polvo_4.xpm";
	
	content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
				img_fr[frames], &content->data->img_width,
				&content->data->img_height);
		frames--;
		if(frames == 0)
			frames = 3;
}


void wall_loop(t_so_long *content)
{
	static int i = 0;
    char *img_fr[5];
	int num_frames;
	int frame_index;
	
	frame_index = 0;
	num_frames = 4;
    img_fr[0] = "images/wall01.xpm";
    img_fr[1] = "images/wall02.xpm";
    img_fr[2] = "images/wall03.xpm";
    img_fr[3] = "images/wall01.xpm";
    img_fr[4] = "images/wall02.xpm";


    frame_index = i / (content->enemies + 1) % num_frames;
   
    content->data->img = mlx_xpm_file_to_image(content->vars->mlx,
                                               img_fr[frame_index],
                                               &content->data->img_width,
                                               &content->data->img_height);
    i++;
}
