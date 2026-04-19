/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 03:14:05 by ahelman           #+#    #+#             */
/*   Updated: 2026/04/19 11:25:00 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
					&& str[i] <= 'Z')))
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

	ft_str_is_alpha(str);
	printf("%d", ft_str_is_alpha(str));
	ft_str_is_alpha(rst);
	printf("%d", ft_str_is_alpha(rst));


}*/