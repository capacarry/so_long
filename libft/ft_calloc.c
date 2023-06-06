/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:46:16 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 15:21:45 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memset(ptr, '\0', nmemb * size);
	}
	return (ptr);
}

// int	main(void)
// {
// 	int *p1 = ft_calloc(4, sizeof(int));
// 	int *p2 = ft_calloc(1, sizeof(int[4]));
// 	int *p3 = ft_calloc(2, 0);

// 	if (p2)
// 	{
// 		for (int n = 0; n < 4; ++n) // print the array
// 			printf("p3[%d] == %d\n", n, p3[n]);
// 	}

// 	free(p1);
// 	free(p2);
// 	free(p3);
// }