/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 05:44:09 by ahelman           #+#    #+#             */
/*   Updated: 2026/04/19 09:16:54 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printing(int array[], int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = array[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (array[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_recursive(int array[], int n, int i)
{
	if (i == 0)
		array[i] = 0;
	else
		array[i] = array[i - 1] + 1;
	while (array[i] < 11 - n + i)
	{
		if (i == n - 1)
			ft_printing(array, n);
		else
			ft_recursive(array, n, i + 1);
		array[i]++;
	}
}

void	ft_print_combn(int n)
{
	int	array[10];

	if (n <= 0 || n >= 10)
	{
		return ;
	}
	ft_recursive(array, n, 0);
}
