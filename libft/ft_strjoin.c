/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:57:16 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 16:16:01 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*conc;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	conc = (char *)malloc(size_s1 + size_s2 + 1);
	if (!conc)
		return (NULL);
	ft_memcpy(conc, s1, size_s1);
	ft_memcpy(conc + size_s1, s2, size_s2 + 1);
	conc[size_s1 + size_s2 + 1] = '\0';
	return (conc);
}
