/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:53 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/15 19:37:24 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	i = 0;
	buffer1 = (unsigned char *) dest;
	buffer2 = (unsigned char *) src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*buffer1 = *buffer2;
		buffer1++;
		buffer2++;
		i++;
	}
	return (dest);
}

/*
int	main()
{
	char	str[] = "goku vs vegeta";
	ft_memcpy(str + 5, str, 7);
	printf("%s", str);
	return (0);
}


int	main()
{
	char	*src = NULL;
	char	*dest = NULL;
	ft_memcpy(dest, src, 4);
	printf("%s", dest);
	return (0);
}
*/