/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:03:50 by ahelman           #+#    #+#             */
/*   Updated: 2026/04/19 11:26:15 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	j;
	unsigned int	d;

	dest_len = 0;
	while (dest_len < size && dest[dest_len])
		dest_len++;
	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (size <= dest_len)
		return (size + src_len);
	j = 0;
	d = dest_len;
	while (src[j] && (dest_len < size - 1))
	{
		dest[dest_len] = src[j];
		j++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (d + src_len);
}
