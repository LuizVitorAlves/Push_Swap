#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

// Funções de movimentação
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// Funções auxiliares
t_list	*ft_lstlast(t_list *lst);
int		stack_size(t_list *stack);
void	index_stack(t_list *stack);
void	sort_array(int *array, int size);
void	ft_putstr_fd(char *s, int fd);

// Funções de ordenação
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);

// Função Radix
void	radix_sort(t_list **stack_a, t_list **stack_b);

// Funções de indexação
void	push_smallest_to_b(t_list **stack_a, t_list **stack_b);

#endif
