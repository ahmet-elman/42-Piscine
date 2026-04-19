/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 04:56:56 by ahelman           #+#    #+#             */
/*   Updated: 2026/04/19 11:24:50 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}
/*#include<stdio.h>

int	main(void)
{
	char str[]= "ahmetELMAN";
	char rst[]= "12114172894";

	ft_str_is_numeric(str);
	printf("%d", ft_str_is_numeric(str));
	ft_str_is_numeric(rst);
	printf("%d", ft_str_is_numeric(rst));


}*/