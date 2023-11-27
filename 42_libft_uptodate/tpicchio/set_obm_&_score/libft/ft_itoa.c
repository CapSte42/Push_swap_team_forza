/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:50:17 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/16 14:55:37 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nmb(int n)
{
	int	nmbl;

	nmbl = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nmbl++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		nmbl++;
	}
	return (nmbl);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nmbl;

	nmbl = ft_nmb(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((nmbl + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[nmbl] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[nmbl - 1] = n % 10 + '0';
		n = n / 10;
		nmbl--;
	}
	return (str);
}

/*
int	main()
{
	int	n;

	n = -30;
	printf("%s\n", ft_itoa(n));
	return (0);
}
*/