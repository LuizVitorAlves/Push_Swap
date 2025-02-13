# Nome do projeto
NAME = push_swap

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Arquivos fonte e objetos
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Funções para compilar e linkar
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Regras para criar os arquivos objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e executável
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

# Regras para a biblioteca libft (se for usada, caso contrário pode ser removida)
# libft.a:
# 	$(MAKE) -C libft

# Para usar a libft, descomente a linha acima e adicione -L./libft -lft nas flags de compilação do Makefile.

.PHONY: all clean fclean re
