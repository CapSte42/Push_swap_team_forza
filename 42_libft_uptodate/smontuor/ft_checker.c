/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:18:17 by smontuor          #+#    #+#             */
/*   Updated: 2023/11/22 12:03:42 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error)
{
	ft_printf(2, "Error\n");
	exit(error);
}

int	ft_is_all_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		if (ft_issign(str[i][j]) == 1)
			j++;
		while (str[i][j] != '\0')
		{
			if (ft_isdigit(str[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_within_int(char **str)
{
	int	i;
	int	num;
	int error;

	i = 0;
	error= 0;
	while (str[i] != NULL)
	{
		num = 0;
		num = ft_atoi(str[i], &error);
		if (error == 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_unique(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		j = i + 1;
		while (str[j] != NULL)
		{
			if (ft_atoi(str[i], NULL) == ft_atoi(str[j], NULL))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_param(int i)
{
	if (i == 1)
		return (0); //input vuoto
	if (i < 3)
		return (-1); //terminare
	return (1); //input valido
}

int main(int ac, char **av)
{
	int	error;

	error = ft_check_param(ac);

	while(ft_get_next_line(0) != NULL && ft_check_param(ac) == 0)
	{
		if (error == -1)
			ft_error(error);
	}
}



