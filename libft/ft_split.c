/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:56:28 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/20 16:04:44 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wtotal(char const *s, char c)
{
	int	wrd_count;
	int	flag;

	wrd_count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			wrd_count++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (wrd_count);
}

static char	*ft_words(char *s, char ch)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != ch)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	i = 0;
	while (*s && *s != ch)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *str, char ch)
{
	size_t	i;
	char	**result;

	if (!str)
		return (0);
	i = 0;
	result = malloc(sizeof(char *) * (ft_wtotal(str, ch) + 1));
	if (!result)
	{
		free(result);
		return (0);
	}
	while (*str)
	{
		if (*str != ch)
		{
			result[i++] = ft_words((char *)str, ch);
			while (*str && *str != ch)
				str++;
		}
		else
			str++;
	}
	result[i] = 0;
	return (result);
}
