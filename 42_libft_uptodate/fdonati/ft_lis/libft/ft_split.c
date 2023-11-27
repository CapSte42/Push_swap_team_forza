/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:36:38 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/17 18:51:04 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **arr, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static size_t	ft_strnmb(const char *s, char c)
{
	size_t	i;
	size_t	nmb;
	char	*str;

	i = 0;
	nmb = 0;
	str = (char *) s;
	if (str[0] != c && str[0] != '\0')
		nmb++;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			nmb++;
		i++;
	}
	return (nmb);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	*str;
	char	**arr;

	j = 0;
	str = (char *) s;
	arr = malloc((ft_strnmb(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (j < ft_strnmb(s, c))
	{
		while (*str == c)
			str++;
		if (ft_strchr(str, c) != 0)
			arr[j] = ft_substr(str, 0, ft_strchr(str, c) - str);
		else
			arr[j] = ft_strdup(str);
		if (arr[j] == NULL)
			return (ft_free(arr, j));
		if (ft_strchr(str, c) != 0)
			str = ft_strchr(str, c);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

/*
int	main()
{
	char	**arr;
	int		i;

	arr = ft_split("", 't');
	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s, ", arr[i]);
		i++;
	}
	printf("%s", arr[i]);
	return (0);
}
*/