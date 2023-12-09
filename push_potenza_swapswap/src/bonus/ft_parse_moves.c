

#include "push_swap.h"

int ft_check_moves(char *moves)
{
	if (!ft_strncmp(moves, "sa\n", 3))
		return (1);
	else if (!ft_strncmp(moves, "sb\n", 3))
		return (2);
	else if (!ft_strncmp(moves, "ss\n", 3))
		return (3);
	else if (!ft_strncmp(moves, "pa\n", 3))
		return (4);
	else if (!ft_strncmp(moves, "pb\n", 3))
		return (5);
	else if (!ft_strncmp(moves, "ra\n", 3))
		return (6);
	else if (!ft_strncmp(moves, "rb\n", 3))
		return (7);
	else if (!ft_strncmp(moves, "rr\n", 3))
		return (8);
	else if (!ft_strncmp(moves, "rra\n", 4))
		return (9);
	else if (!ft_strncmp(moves, "rrb\n", 4))
		return (10);
	else if (!ft_strncmp(moves, "rrr\n", 4))
		return (11);
	else
		return (0);
}

void    ft_parse_moves(t_list **stack_a, t_list **stack_b)
{
    int scenario;
    while ((moves = get_next_line(0)) != NULL)
    {
        scenario = ft_check_moves(moves);
        //ft_do_scenario(scenario, stack_a, stack_b);
        ft_printf(2, "%d\n", scenario);
       // free(line); // Assicurati di liberare la memoria se get_next_line alloca memoria
    }
    printf("EOF ricevuto o errore. Uscita dal programma.\n");
}

