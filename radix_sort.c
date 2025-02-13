#include "pushswap.h"

// Retorna o número de bits necessários para representar o maior índice
static int max_bits(t_list *stack)
{
    int max = 0;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

// Implementação do Radix Sort
void radix_sort(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_a); // Tamanho total da stack
    int max_bit = max_bits(*stack_a); // Número máximo de bits do maior índice
    int i = 0;

    while (i < max_bit) // Percorre bit a bit
    {
        int j = 0;
        int original_size = size;
        while (j < original_size)
        {
            if ((((*stack_a)->index >> i) & 1) == 0)
                pb(stack_a, stack_b); // Move para stack_b se o bit for 0
            else
                ra(stack_a); // Rotaciona stack_a se o bit for 1
            j++;
        }
        while (*stack_b) // Retorna os elementos para stack_a
            pa(stack_a, stack_b);
        i++;
    }
}
