/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:57:54 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 14:58:17 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;
	int				diff;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while ((c1[i] != '\0' || c2[i]) != '\0' && i < n)
	{
		if (c1[i] != c2[i])
		{
			diff = c1[i] - c2[i];
			return (diff);
		}
		i++;
	}
	if (i == n)
		return (0);
	return (c1[i] - c2[i]);
}
