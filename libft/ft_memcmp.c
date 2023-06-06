/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:57:29 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 14:57:45 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr_1;
	char	*ptr_2;
	size_t	i;

	ptr_1 = (char *)s1;
	ptr_2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr_1[i] != ptr_2[i])
			return ((unsigned char)ptr_1[i] - (unsigned char)ptr_2[i]);
		i++;
	}
	return (0);
}
