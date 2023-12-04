/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:16:36 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/15 19:30:53 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (s1 == 0)
		return (0);
	while (ft_strchr(set, s1[start]) != 0)
		start++;
	while (ft_strchr(set, s1[end]) != 0)
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}

/*
int	main()
{
	char	*s1 = "goku vs vegeta";
	char	*set = " ga";
	char	*str;

	str = ft_strtrim(s1, set);
	printf("%s", str);
	return (0);
}
*/