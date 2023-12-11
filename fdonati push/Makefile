#-----------Dichiarazione di nomi e percorsi in variabili
NAME        := push_swap
LIB        	:= ft
LIB_TARGET 	:= libft/libft.a
INCS        := \
	./include
SRC_DIR     := src
#-----------File da compilare per push_swap
SRCS        := \
				ft_push_swap.c \
				ft_check_token.c \
				ft_error.c \
				ft_last_rotate.c \
				ft_lis_crcl.c \
				ft_lis_lin.c \
				ft_lis_utils.c \
				ft_lis.c \
				main.c \
				ft_moves_p.c \
				ft_moves_r.c \
				ft_moves_s.c \
				ft_obm_score_utils.c \
				ft_obm_score.c \
				ft_push_best.c \
				ft_set_index.c \
				ft_set_list.c \
				ft_set_obm_dist_utils.c \
				ft_set_obm_dist.c \
				ft_set_swap.c \
				ft_split_input_into_token.c \
				ft_swapswap.c
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
#-----------File da compilare per checker
CHECKER		:= \
	src/ft_error.c \
	src/ft_split_input_into_token.c \
	src/ft_check_token.c \
	src/ft_set_list.c \
	src/ft_moves_p.c \
	src/ft_moves_r.c \
	src/ft_moves_s.c \
	src/bonus/ft_parse_moves.c \
	src/bonus/ft_stacks_are_cool.c \
	src/bonus/ft_checker.c

BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
#-----------tutti i file .o vengono inseriti nella cartella nascosta .build. vengono compilati anche file .d che contengono i link delle dipendenze
CC          := clang
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIB_TARGET)))
LDLIB      	:= $(addprefix -l,$(LIB))
#-----------clang alternativa a cc o gcc. il resto sono flag per includere librerie
RM          := rm -rf
MAKEFLAGS   := --no-print-directory # non stampa le entrate e le uscite dalle directory per compilazione file
DIR_DUP     = mkdir -p $(@D) #chiedere a chatgpt, lunga da spiegare

.PHONY: clean fclean re
.SILENT: #esegue il makefile in maniera silenziosa, non stampa nulla

# Rules ----------------------------------------------------------------------->

all: goku banner $(NAME)

$(NAME): $(OBJS) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME)
	${info }
	${info ${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}}
	${info }

$(LIB_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}

-include $(DEPS)

clean:
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(BUILD_DIR)
	$(RM) checker.d
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}}

fclean: clean
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)
	$(RM) checker

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: banner $(LIB_TARGET)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CHECKER) $(LDFLAGS) $(LDLIB) -o checker
	${info ${BOLD}Creating  -> ${BLUE}checker${NO_COLOR}}

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

banner:
	@echo '${RED}                                                      '
	@echo '                                      /\\\                  '
	@echo '                                      \/\\\                 '
	@echo '/\\\\\\\\\                             \/\\\                '
	@echo '/\\\/////\\\  /\\\    /\\\  /\\\\\\\\\\ \/\\\               '
	@echo '\/\\\\\\\\\\  \/\\\   \/\\\ \/\\\//////  \/\\\\\\\\\\       '
	@echo ' \/\\\//////   \/\\\   \/\\\ \/\\\\\\\\\\ \/\\\/////\\\     '
	@echo '  \/\\\         \/\\\   \/\\\ \////////\\\ \/\\\   \/\\\    '
	@echo '   \/\\\         \//\\\\\\\\\   /\\\\\\\\\\ \/\\\   \/\\\   '
	@echo '    \///           \/////////   \//////////  \///    \///   '
	@echo '                                                /\\\\\\\\\  '
	@echo '  /\\\\\\\\\\  /\\    /\\   /\\  /\\\\\\\\\     /\\\/////\\\'
	@echo '  \/\\\//////  \/\\\  /\\\\ /\\\ \////////\\\   \/\\\\\\\\\\'
	@echo '   \/\\\\\\\\\\ \//\\\/\\\\\/\\\    /\\\\\\\\\\  \/\\\//////'
	@echo '    \////////\\\  \//\\\\\/\\\\\    /\\\/////\\\  \/\\\     '
	@echo '      /\\\\\\\\\\   \//\\\\//\\\    \//\\\\\\\\/\\ \/\\\    '
	@echo '      \//////////     \///  \///      \////////\//  \///    '
	@echo ''
	@echo '            ✨ ${BOLD}push_swap ✨'
	@echo '${NO_COLOR}'

# ------------------------------------------------------------------------------

goku:
	@echo '⣿⣿⠿⠿⠿⠿⣿⣷⣂⠄⠄⠄⠄⠄⠄⠈⢷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣷⡾⠯⠉⠉⠉⠉⠚⠑⠄⡀⠄⠄⠄⠄⠄⠈⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡀⠄⠄⠄⠄⠄⠄⠄⠄⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠎⠄⠄⣀⡀⠄⠄⠄⠄⠄⠄⠄⠘⠋⠉⠉⠉⠉⠭⠿⣿'
	@echo '⡀⠄⠄⠄⠄⠄⠄⠄⠄⡇⠄⣠⣾⣳⠁⠄⠄⢺⡆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄'
	@echo '⣿⣷⡦⠄⠄⠄⠄⠄⢠⠃⢰⣿⣯⣿⡁⢔⡒⣶⣯⡄⢀⢄⡄⠄⠄⠄⠄⠄⣀⣤⣶'
	@echo '⠓⠄⠄⠄⠄⠄⠸⠄⢀⣤⢘⣿⣿⣷⣷⣿⠛⣾⣿⣿⣆⠾⣷⠄⠄⠄⠄⢀⣀⣼⣿'
	@echo '⠄⠄⠄⠄⠄⠄⠄⠑⢘⣿⢰⡟⣿⣿⣷⣫⣭⣿⣾⣿⣿⣴⠏⠄⠄⢀⣺⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣷⠶⠄⠄⠄⠹⣮⣹⡘⠛⠿⣫⣾⣿⣿⣿⡇⠑⢤⣶⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣯⣤⣤⣤⣤⣀⣀⡹⣿⣿⣷⣯⣽⣿⣿⡿⣋⣴⡀⠈⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣝⡻⢿⣿⡿⠋⡒⣾⣿⣧⢰⢿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⣏⣟⣼⢋⡾⣿⣿⣿⣘⣔⠙⠿⠿⠿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⣛⡵⣻⠿⠟⠁⠛⠰⠿⢿⠿⡛⠉⠄⠄⢀⠄⠉⠉⢉'
	@echo '⣿⣿⣿⣿⡿⢟⠩⠉⣠⣴⣶⢆⣴⡶⠿⠟⠛⠋⠉⠩⠄⠉⢀⠠⠂⠈⠄⠐⠄⠄⠄'