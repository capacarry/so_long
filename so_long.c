/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:26:49 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/06 15:50:03 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc,char *argv[])
{	
	t_so_long content;
	
	if (argc != 2)
	{
		perror("Wrong Number of arguments\n");
		exit(1);	
	}
	if(map_format_checker(argc,argv[1]))
	{	
		if(!open(argv[1],content.map_fd))
		{
			perror("Failure opening file");
			exit(1);
		}
		if(!map_layout_checker(&content))
		{
			close(content.map_fd);
			perror("This Map isn't valid acording to game rules and formating.\n");
			exit(1);
		}
	}
}