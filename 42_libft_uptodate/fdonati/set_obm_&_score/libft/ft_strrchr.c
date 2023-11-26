/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:09:44 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/15 17:37:52 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = ft_strlen(str);
	str = str + i;
	while (i >= 0)
	{
		if ((char) c == *str)
			return ((char *) str);
		i--;
		str--;
	}
	return (0);
}

/*
int	main()
{
	char	*str = "vegeta";
	char	c = 'v';
	printf("%s", ft_strrchr(str, c));
	return (0);
}
*/