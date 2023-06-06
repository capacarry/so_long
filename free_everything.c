/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:12:41 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/06 13:30:32 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_double_array(t_so_long *content)
{	
	int i;

	i = -1;
	while(content->map[++i])
		free(content->map[i]);
	free(content->map);
}