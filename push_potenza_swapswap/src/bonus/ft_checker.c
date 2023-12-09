
/* Spiegazione veloce di come funziona il checker:
.
-Il checker viene lanciato dandogli in input COME ARGOMENTO una lista di numeri, ossia lo stack A.
-I numeri vengono anzitutto parsati, e poi vengono inseriti in lista.
-La lista in cui vengono inseriti avrà il content a ssize_t (come size_t ma include anche i numeri negativi)

Gli altri dati della t_data non servono, in quanto, successivamente a questi passaggi, il checker manterrà aperto lo stdin. 

-Da questo momento in poi il checker accetterà i nomi delle mosse. 
-Queste verranno parsate, riconosciute ed eseguite.
-Dopo ogni mossa si va a capo e si attende la prossima istruzione. 
-L input del checker si fermerà non appena si chiuderà lo stdin, con ctrl+d. 
-Allora, e solo allora, farà 2 check. Controllerà se stack_a è in ordine crescente e se stack_b è vuota.
-Attenzione, è vuota significa che fino a quel momento deve esistere. 
-A quel punto stamperà ok o ko, o qualche altro messaggio buffo. 
-A quel punto fria tutto e tanti saluti.  */

#include "push_swap.h"
#include "libft.h"

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

void    ft_parse_moves(/* t_list **stack_a, t_list **stack_b */)
{
    int scenario;
    char *moves;

    scenario = 1;
	ft_printf(2,"%d\n", ft_itoa(scenario));
    while (scenario != 0)
    {
		ft_printf(2,"pd-\n");
        moves = ft_get_next_line(0);
		ft_printf(2,"pd-\n");
		scenario = ft_check_moves(moves);
		ft_printf(2,"pd-\n");
        //ft_do_scenario(sc,enario, stack_a, stack_b);
        ft_printf(1, "%s : %d\n", moves, scenario);
        //free(moves); // Assicurati di liberare la memoria se get_next_line alloca memoria
    }
    printf("EOF ricevuto o errore. Uscita dal programma.\n");
}

int main(int ac, char **av)
{
    char	**token;
	//char	*moves;
	t_list	*stack_a;
	//t_list	*stack_b;
	ft_printf(2,"pd\n");
	token = ft_split_input_into_token(ac, av);
	ft_printf(2,"pd\n");
	ft_check_token(token);
	ft_printf(2,"pd\n");
	ft_set_list(&stack_a, token);
	ft_printf(2,"pd\n");
	ft_free_matrix(token);
	ft_printf(2,"pd\n");
    //stack_b = NULL;
    ft_parse_moves(/* &stack_a, &stack_b */);
	ft_printf(2,"pd+\n");
   // ft_stacks_are_cool(stack_a, stack_b);
   // ft_free_all(stack_a, stack_b, moves);
    return (0);
}