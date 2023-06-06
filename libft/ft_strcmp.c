/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:41:33 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/04/19 14:57:59 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//   char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
//   int result;

//   // comparing strings str1 and str2
//   result = ft_strcmp(str1, str2);
//   printf("strcmp(str1, str2) = %d\n", result);

//   // comparing strings str1 and str3
//   result = ft_strcmp(str1, str3);
//   printf("strcmp(str1, str3) = %d\n", result);

//   return (0);
// }