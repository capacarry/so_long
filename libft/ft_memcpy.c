/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:19:17 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 15:46:20 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*first;
	char		*last;

	first = (char *)src;
	last = (char *)dest;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*last = *first;
		first++;
		last++;
		n--;
	}
	return (dest);
}

// int main()
// {
// 	char src[] = "WhatsGood";
//     char src_2[] = "WhatsGood";
// 	unsigned int size = 4;
// 	printf("%s\n",(char *)ft_memcpy(src ,src + 2,size));
//     printf("%s\n",(char *)memcpy(src ,src_2 + 2,size));
// 	return(0);
// }
