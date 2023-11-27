/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:36:39 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/15 15:51:26 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	while (dst_len + i + 1 < size && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
	{
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	else
		return (src_len + size);
}

/*
int	main()
{
	char	dst[14] = "vegeta";
	char	src[20] = "ssj2 vs goku";
	int		size;

	size = 15;
	printf("%ld\n", ft_strlen(src));
	printf("%ld\n", ft_strlcat(dst, src, size));
	printf("%s\n", dst);
	return (0);
}
*/