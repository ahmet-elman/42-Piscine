/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 05:45:55 by ahelman           #+#    #+#             */
/*   Updated: 2025/11/11 07:01:06 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_yazdir(char d)
{
	write(1, &d, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				ft_yazdir(a + '0');
				ft_yazdir(b + '0');
				ft_yazdir(c + '0');
				if (!(a == 7))
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}
