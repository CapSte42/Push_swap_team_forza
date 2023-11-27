/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:49:25 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/15 19:02:18 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		src = malloc(sizeof(char));
		if (src == NULL)
			return (NULL);
		src[0] = '\0';
		return (src);
	}
	if (ft_strlen(s + start) <= len)
		src = ft_strdup(s + start);
	else
	{
		src = malloc((len + 1) * sizeof(char));
		if (src == NULL)
			return (NULL);
		ft_strlcpy(src, s + start, len + 1);
	}
	return (src);
}

/*
int	main()
{
	char	*src = "";
	char	*dst;

	dst = ft_substr(src, 1, 1);
	printf("%s", dst);
	return (0);
}
*/