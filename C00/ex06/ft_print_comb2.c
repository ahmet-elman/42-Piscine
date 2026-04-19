/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 07:04:46 by ahelman           #+#    #+#             */
/*   Updated: 2025/11/11 09:20:56 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_yazici(char ahmet)
{
	write(1, &ahmet, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	e;

	a = 0;
	while (a < 99)
	{
		e = a + 1;
		while (e < 100)
		{
			ft_yazici(a / 10 + '0');
			ft_yazici(a % 10 + '0');
			ft_yazici(' ');
			ft_yazici(e / 10 + '0');
			ft_yazici(e % 10 + '0');
			if (!(a == 98))
			{
				ft_yazici(',');
				ft_yazici(' ');
			}
			e++;
		}
		a++;
	}
}
