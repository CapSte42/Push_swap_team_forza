/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:10:28 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/11 18:56:05 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*buffer;

	i = 0;
	buffer = (unsigned char *) s;
	while (i < n)
	{
		*buffer = c;
		buffer++;
		i++;
	}
	return (s);
}

/*
int main() 
{
	char arr[10];
	int i = 0;

	printf("%s", ft_memset(arr, 'X', 10));
return 0;
}
*/