/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:50:24 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/11 13:53:37 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*buffer;

	buffer = (char *) s;
	while (n > 0)
	{
		if (*buffer == (char) c)
			return ((void *) buffer);
		buffer++;
		n--;
	}
	return (0);
}
