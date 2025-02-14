# Nome do executável
NAME = push_swap

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Diretórios
SRCDIR = .
MOVESDIR = moves

# Arquivos fonte
SRC = $(SRCDIR)/main.c $(SRCDIR)/index.c $(SRCDIR)/radix_sort.c $(SRCDIR)/small_sort.c $(SRCDIR)/utils.c \
      $(SRCDIR)/extra.c $(SRCDIR)/stack_utils.c \
      $(MOVESDIR)/push.c $(MOVESDIR)/reverse_rotate.c $(MOVESDIR)/rotate.c $(MOVESDIR)/swap.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Regra principal: compilar e criar o executável
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Regra para compilar arquivos .c em .o, garantindo que os arquivos dentro de "moves/" encontrem o pushswap.h
$(MOVESDIR)/%.o: $(MOVESDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza de arquivos objeto
clean:
	rm -f $(OBJ)

# Limpeza total (arquivos objeto + executável)
fclean: clean
	rm -f $(NAME)

# Recompilar do zero
re: fclean $(NAME)

.PHONY: all clean fclean re
