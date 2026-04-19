/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:28:05 by ahelman           #+#    #+#             */
/*   Updated: 2026/04/19 10:25:49 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_ultimate_strlen(char **str, int size)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len = total_len + ft_strlen(str[i]);
		i++;
	}
	return (total_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		total_len;
	int		i;

	total_len = ft_ultimate_strlen(strs, size) + (size - 1) * ft_strlen(sep);
	if (size == 0)
	{
		joined = (char *)malloc(sizeof(char) * 1);
		joined[0] = '\0';
		return (joined);
	}
	joined = (char *)malloc(sizeof(char) * (total_len + 1));
	joined[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(joined, strs[i]);
		if (!(i == (size - 1)))
			ft_strcat(joined, sep);
		i++;
	}
	return (joined);
}

// #include <stdio.h>
// int main()
// {
// 	char *resultado;
// 	char *strs[] = {"Ricardo", "da", "Costa", "Moraes", "palvra5"};
// 	char *separador = ", ";

// 	resultado = ft_strjoin(5, strs, separador);
// 	printf("%s\n", resultado);
// 	free(resultado);
// }


//tr//benim yazdığım ft_strjoin yapay zekadan(moulinette) geçmediği için bu kısmı başka bir meslektaşımdan aldım :)

//eng//As the ft_strjoin function I wrote failed the AI test (Moulinette), I borrowed this section from a colleague :)