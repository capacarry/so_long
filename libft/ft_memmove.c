/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:11:57 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 14:57:50 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if (dest == src)
	{
		return (dest);
	}
	else if (dest > src)
	{
		while (i--)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// int main()
// {
// 	char src[] = "WhatsGood";
// 	unsigned int size = 3;
// 	printf("%s\n",(char *)ft_memmove(src + 2,src + 2,size));
//   printf("%s\n",(char *)memmove(src + 2,src + 2,size));
// 	return(0);
// }