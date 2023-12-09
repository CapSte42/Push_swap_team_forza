
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



void	ft_free_all(t_list **stack_a, t_list **stack_b, char **token)
{
	if (token)
		ft_free_matrix(token);
	if (*stack_a)
		ft_lstclear(stack_a, free);
	if (*stack_b)
		ft_lstclear(stack_b, free);
}
int main(int ac, char **av)
{
    char	**token;
	int	illegal_moves;
	int they_are_cool;

	they_are_cool = 0;
	illegal_moves = 0;
	t_list	*stack_a;
	t_list	*stack_b;
	token = ft_split_input_into_token(ac, av);
	ft_check_token(token);
	ft_set_list(&stack_a, token);
    stack_b = NULL;
	illegal_moves = ft_parse_moves(&stack_a, &stack_b);
	they_are_cool = ft_stacks_are_cool(&stack_a, &stack_b);
	ft_free_all(&stack_a, &stack_b, token);
	if (they_are_cool == 1)
	{
		ft_printf(1, "OK");
		if (illegal_moves != 0)
			ft_printf(1, " but with %d illegal moves", illegal_moves);
	} else
		ft_printf(1, "KO");
	ft_printf(1, "\n");
    return (0);
}
