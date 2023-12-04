/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:53:57 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/11 16:13:21 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*src;

	src = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (src == 0)
		return (0);
	ft_strlcpy(src, s, ft_strlen(s) + 1);
	return (src);
}
