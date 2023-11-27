/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:54:19 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/15 17:15:09 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *) s;
	while (*str != '\0')
	{
		if ((char) c == *str)
			return ((char *) str);
		str++;
	}
	if ((char) c == *str)
		return ((char *) str);
	return (0);
}

/*
int	main()
{
	char	*str = "vegeta";
	char	c = '\0';
	printf("%s", ft_strchr(str, c));
	return (0);
}
*/