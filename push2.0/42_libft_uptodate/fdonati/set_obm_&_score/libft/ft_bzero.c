/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:51:03 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/21 16:51:48 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*buffer;

	i = 0;
	buffer = (char *) s;
	while (i < n)
	{
		*buffer = 0;
		buffer++;
		i++;
	}
}

/*
int	main()
{
	char arr[10];
	int i = 0;

	ft_bzero(arr, 10);
	while (i < 10)
	{
		printf("%d", arr[i]);
		i++;
	}
	return (0);
}
*/