/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:27:59 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/27 15:42:52 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_cell(int x, int y, int rows, int cols) 
{
   return (x > 0 && x < rows - 1 && y > 0 && y < cols - 1);
}

void flood_fill_recursive(t_so_long *content, int x, int y, int visited[][MAX_COLS], int *count) 
{
    int rows;
    int cols;

    rows = content->rows; 
    cols = content->cols;
    

	  if(content->map[x][y] == 'E')
    {
        content->found_exit = 1;
    }
    
    if (!is_valid_cell(x, y, rows, cols) || visited[x][y] || content->map[x][y] == '1' || content->map[x][y] == 'X' || content->map[x][y] == 'E') 
    {
        return;
    }

    visited[x][y] = 1;

    if (content->map[x][y] == 'C') 
    {
        (*count)++;
    }
    flood_fill_recursive(content, x - 1, y, visited, count); 
    flood_fill_recursive(content, x + 1, y, visited, count);
    flood_fill_recursive(content, x, y - 1, visited, count);
    flood_fill_recursive(content, x, y + 1, visited, count);
}

int flood_fill(t_so_long *content) 
{
    int visited[MAX_ROWS][MAX_COLS] = {0};
    int count = 0;
    int start_x = 1;
    int start_y = 1;

    flood_fill_recursive(content, start_x, start_y, visited, &count);

    if (count == content->collect && content->found_exit == 1) 
        return 1;
    else
	{	
        return 0;
	}
}