/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:05:06 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 14:58:24 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	cr;
	int				size_s;

	ptr = 0;
	cr = c;
	size_s = ft_strlen(s);
	while (size_s >= 0)
	{
		if (s[size_s] == cr)
		{
			ptr = (char *)s + size_s;
			return (ptr);
		}
		size_s--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
//   char str[] = "This is a sample string";
//   char * pch;
//   pch=strrchr(str,'s');
//   printf ("Last occurence of 's' found at %ld \n",pch-str+1);
//   return (0);
// }