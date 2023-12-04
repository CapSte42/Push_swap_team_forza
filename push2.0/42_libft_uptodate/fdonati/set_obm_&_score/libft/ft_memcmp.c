/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:54:11 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/10 17:54:13 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	i = 0;
	buffer1 = (unsigned char *) s1;
	buffer2 = (unsigned char *) s2;
	while (i < n)
	{
		if (buffer1[i] != buffer2[i])
			return ((int) buffer1[i] - (int) buffer2[i]);
		i++;
	}
	return (0);
}

/*
int	main()
{
	char	*s1 = "vegeta";
	char	*s2 = "vegeth";
	size_t	n = 6;

	printf("%d", ft_memcmp(s1, s2, n));
	return (0);
}
*/