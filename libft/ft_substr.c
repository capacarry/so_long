/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:15:36 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/28 16:21:29 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*sub_s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		sub_s = malloc(sizeof(char));
	else if (len >= ft_strlen(s))
		sub_s = malloc(ft_strlen(s) - start + 1);
	else
		sub_s = malloc(len + 1);
	if (sub_s == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			sub_s[j++] = s[i];
		i++;
	}
	sub_s[j] = '\0';
	return (sub_s);
}
