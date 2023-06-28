/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_break.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:32:26 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/28 16:43:21 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_break(t_so_long *content)
{
	int		i;
	int		j;

	i = 0;
	while (content->map[i] != NULL)
	{
		j = 0;
		while (content->map[i][j] != '\0')
		{
			if (content->map[i][j] == '\n')
				content->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}
