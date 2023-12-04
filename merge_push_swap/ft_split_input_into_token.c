#include "libft.h"
#include "push_swap.h"

static void	ft_free_token(char **result, int i)
{
	i--;
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
	ft_error(-2, NULL, NULL);
}

static char	**ft_one_arg(char *str, char sep)
{
	char	**token;

	sep = ' ';
	token = ft_split(str, sep);
	if (token == NULL)
		ft_error(0, NULL, NULL);
	return (token);
}

static char	**ft_multiple_arg(char **matrix, int size)
{
	char	**token;
	int		i;

	i = 1;
	token = malloc(size * sizeof(char *));
	if (token == NULL)
		ft_error(-2, NULL, NULL);
	while (i < size)
	{
		token[i - 1] = ft_strdup(matrix[i]);
		if (token[i - 1] == NULL)
			ft_free_token(token, i);
		i++;
	}
	token[size - 1] = NULL;
	return (token);
}

char	**ft_split_input_into_token(int ac, char **av)
{
	char	**token;

	token = NULL;
	if (ac < 2)
	{
		ft_error(0, NULL, NULL);
	}
	else if (ac == 2)
	{
		token = ft_one_arg(av[1], ' ');
	}
	else if (ac > 2)
	{
		token = ft_multiple_arg(av, ac);
	}
	return (token);
}
