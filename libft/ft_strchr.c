/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:32:48 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 14:57:56 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*ptr;
	unsigned char	c1;

	ptr = (char *)s;
	c1 = c;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c1)
			return (ptr + i);
		i++;
	}
	if (ptr[i] == c1)
		return ((char *)s + i);
	return (NULL);
}

// int main()
// {
//     char buffer1[SIZE] = "computer program";
//     char * ptr;
//     int    ch = 'p';

//     ptr = strchr( buffer1, ch );
//     printf( "The first occurrence of %c in '%s' is '%s'\n", ch, buffer1,
//		ptr );

// }