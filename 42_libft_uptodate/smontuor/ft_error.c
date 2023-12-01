#include "libft.h"
#include "push_swap.h"

void	ft_free_token_array(char **token)
{
	int i;

	i = 0;
	if (token != NULL)
	{
		while (token[i] != NULL)
		{
			free(token[i]);
			i++;
		}
		free(token);
	}
}

void	ft_error(int error, char **token, t_list **lst)
{
	if (error == -1) //errore di formattazione dell input
	{
		ft_printf(2, "Error\n");
		ft_free_token_array(token);
	}
	if (error == -2) //errore di malloc
		ft_printf(2, "Malloc error\n");
	if (error == -3) //errore improbabile
		ft_printf(2, "Strange error\n");
	if (error == -4) //errore sulla lista
	{
		ft_printf(2, "Malloc list error\n");
		ft_free_token_array(token);
		ft_lstclear(lst, free);
	}
	exit(error);
}