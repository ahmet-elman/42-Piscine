/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 01:57:18 by ahelman           #+#    #+#             */
/*   Updated: 2025/11/11 02:21:58 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	rakam;

	rakam = '0';
	while (rakam <= '9')
	{
		write(1, &rakam, 1);
		rakam++;
	}
}
