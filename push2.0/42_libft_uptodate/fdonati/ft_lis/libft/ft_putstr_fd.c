/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:21:06 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/16 18:48:27 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	l;

	if (fd < 0)
		return ;
	l = ft_strlen(s);
	write(fd, s, l);
}

/*
int    main()
{
    char	*str;

    str = "red eyes black dragon";
    ft_putstr_fd(str, 1);
    return (0);
}
*/