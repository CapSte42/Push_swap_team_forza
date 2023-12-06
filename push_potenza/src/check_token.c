#include "libft.h"
#include "push_swap.h"

static void	ft_is_all_digit(char **token)
{
	int	i;
	int	j;

	if (token == NULL)
		ft_error(3, NULL, NULL);
	i = 0;
	while (token[i] != NULL)
	{
		j = 0;
		if (token[i][j + 1] != '\0' && ft_issign(token[i][j]) == 1)
			j++;
		while (token[i][j] != '\0')
		{
			while (token[i][j] != '\0' && ft_isspace(token[i][j]) == 1)
				j++;
			if (token[i][j] != '\0' && ft_isdigit(token[i][j]) == 0)
			{
				ft_error(1, token, NULL);
			}
			j++;
		}
		i++;
	}
}

static void	ft_within_int(char **token)
{
	int	i;
	int	error;

	if (token == NULL)
		ft_error(3, NULL, NULL);
	i = 0;
	error = 0;
	while (token[i] != NULL)
	{
		if (ft_strncmp(token[i], "-0", 3) == 0)
		{
			ft_printf(2, "Error: ...-0? Really?\n");
			ft_error(0, token, NULL);
		}
		ft_atoi(token[i], &error);
		if (error == 1)
		{
			ft_error(1, NULL, NULL);
		}
		i++;
	}
}

static void	ft_is_unique(char **token)
{
	int	i;
	int	j;
	int	error;

	error = 0;
	if (token == NULL)
		ft_error(3, NULL, NULL);
	i = 0;
	while (token[i + 1] != NULL)
	{
		j = i + 1;
		while (token[j] != NULL)
		{
			if (ft_atoi(token[i], &error) == ft_atoi(token[j], &error))
			{
				ft_error(1, token, NULL);
			}
			j++;
		}
		i++;
	}
}

static void	ft_infamous_int(char **token)
{
	int	i;

	if (token == NULL)
		ft_error(3, NULL, NULL);
	i = 0;
	while (token[i])
	{
		if (token[i][0])
			if (ft_issign(token[i][0]) == 1 || token[i][0] == '0')
				if (token[i][1])
					if (token[i][2] && token[i][1] == '0')
						ft_error(1, token, NULL);
		i++;
	}
}

void	ft_check_token(char **token)
{
	ft_is_all_digit(token);
	ft_within_int(token);
	ft_is_unique(token);
	ft_infamous_int(token);
}
