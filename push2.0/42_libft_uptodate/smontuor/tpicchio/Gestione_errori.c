INDEXING.c

/* presumo che la lista che gli arriva sia gia' controllata e non NULL ma comunque
ci sarebbe da mettere un check iniziale nella indexing(). */

/* ft_fill_stack()
da proteggere malloc per la creazione dell'array (stack) linea 57.  */

/* dopo la chiamata della ft_fill_stack linea 78 check sulla validita' dell'array anche se gia' controllato prima.
 */
/* ft_quick_sort() non alloca niente ma andrebbe in errore se la ft_lstsize() non funziona correttamente.
 */
/* gia' gestita la free dell'array, eventualmente si puo' cambiare la funzione in void forse meglio listclear?
 */

SET_SWAP.c

/* questa funzione non alloca niente, gli unici errori che mi vengono in mente sono se la lista gli arriva vuota (molto improbabile)
e se fallisce la ft_sx() linea 40 ma credo saranno gestiti gli errori al suo interno. */
tutte le mosse vanno controllate nell ottica del checker

CORE.c

prima calloc per la stringa moves da gestire se non gia' fatto nella calloc, linea 77.

set_stacks()

la funzione non fa malloc per lo stack_b perche' lo stack avra' all'interno i nodi dello stack_a
da gestire le chiamate delle strjoin oppure cambiarle in chiamate della freejoin che magari gestisce gli errori all'interno.
ho commentato la chiamata alla ft_cazzi perche' ho fatto dei test e delle volte rende il programma meno efficiente a livello di mosse totali.


ft_remove_ra()

qui c'e' un leak di memoria quando va a creare la matrice split tramite la ft_split non so da cosa e' dovuto, valgrind lo traccia fino alla ft_substr.
gestire fallimento della calloc di new, linea 28.
la funzione freea moves che sono le vecchie mosse e la split che e' la matrice d'appoggio.


dentro il while (stack_b) ci sono le funzioni obm di Fra e la ft_push_best che e' in un altro file.


dopo la chiamata della ft_last_rotate (gestita dopo) si potrebbe gia' stampare le mosse totali e fare la free generale visto che il programma e' finito,
non so se serva a qualcosa restituire le mosse al main ma per adesso la ft_calcute le restituisce.



PUSH_BEST.c

la funzione non fa malloc, aggiungere i controlli sulle strjoin.



LAST_ROTATE.c

la funzione non fa malloc, aggiungere i controlli sulle strjoin.


I file moves.c e swap_moves.c contengono le mosse che tornano NULL se gli arriva gli stack vuoti.
