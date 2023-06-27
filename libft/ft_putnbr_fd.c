/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:43:34 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/23 16:39:50 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*aplicamos recursividade para fazer a divisao sucessiva
de "n" escrevendo casa decimal a casa decimal o resto
da divisao por 10 nosso numero convertido + 48 (ascii).*/
void	ft_putnbr_fd(int n)
{
	long long int	t;

	t = n;
	if (t < 0)
	{
		t *= -1;
		ft_putchar_fd('-');
	}
	if (t > 9)
	{
		ft_putnbr_fd(t / 10);
		ft_putchar_fd(t % 10 + '0');
	}
	else
		ft_putchar_fd(t + '0');
}
