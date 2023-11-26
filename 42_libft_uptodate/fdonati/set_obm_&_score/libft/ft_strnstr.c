/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:14:13 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/11 19:00:00 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		while (little[j] != '\0' && big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *) big + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

/*
int	main()
{
	char *big = "blue eyes white dragon attack directly the life points";
	char *little = "point";
	size_t len = 69;

	printf("%s", ft_strnstr(big, little, len));
	return (0);
}
*/