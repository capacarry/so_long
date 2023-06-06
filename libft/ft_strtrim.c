/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:26:32 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/21 17:17:00 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;

	start = s1;
	while (*start && ft_strchr(set, *start))
	{
		start++;
	}
	end = s1 + ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, *end))
	{
		end--;
	}
	return (ft_substr(start, 0, end - start + 1));
}
