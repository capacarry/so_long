/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:10:11 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 14:57:41 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;
	char	cr;

	i = 0;
	ptr = (char *)s;
	cr = c;
	while (i < n)
	{
		if (*ptr == cr)
		{
			return ((void *)ptr);
		}
		i++;
		ptr++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char search[] = "TechOnTheNet";
// 	char *ptr;

// 	/* Return a pointer to the first 'N' within the search string */
// 	ptr = (char *)ft_memchr(search, 'N', strlen(search));

// 	/* If 'N' was found, print its location (This should produce "10") */
// 	if (ptr != NULL)
// 		printf("Found 'N' at position %ld.\n", 1 + (ptr - search));
// 	else
// 		printf("'N' was not found.\n");

// 	return (0);
// }