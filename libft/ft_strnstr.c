/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:30:59 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 14:58:21 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*big && len >= little_len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

// int main ()
// {
//     char main_string[50] = "Hello, how's the weather today?";
//     char search_string[30] = "weather";

//     char *found_string = strstr(main_string, search_string);

//     if (found_string == NULL)
//     {
//         printf ("Substring not found in the string");
//     }
//     else
//     {
//         printf ("Substring located -> %s", found_string);
//     }

//     return (0);
// }
