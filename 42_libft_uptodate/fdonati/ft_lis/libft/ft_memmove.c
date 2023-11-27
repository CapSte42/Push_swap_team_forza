/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:52:16 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/11 16:25:04 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	i = 0;
	buffer1 = (unsigned char *) dest;
	buffer2 = (unsigned char *) src;
	if (buffer1 > buffer2)
	{
		buffer1 = buffer1 + n - 1;
		buffer2 = buffer2 + n - 1;
		while (i < n)
		{
			*buffer1 = *buffer2;
			buffer1--;
			buffer2--;
			i++;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

/*
int	main()
{
	char	str[] = "goku vs vegeta";
	char	*dest;
	dest = ft_memmove(str + 5, str, 7);
	printf("%s", str);
	printf("%s", "\n");
	printf("%s", dest);
	return (0);
}
*/