#include "pushswap.h"

// Ordena uma stack com apenas dois elementos
void sort_two(t_list **stack)
{
    if ((*stack)->content > (*stack)->next->content)
        sa(stack);
}

// Ordena uma stack com três elementos
void sort_three(t_list **stack)
{
    int a = (*stack)->content;
    int b = (*stack)->next->content;
    int c = (*stack)->next->next->content;

    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

// Ordena uma stack com quatro elementos
void sort_four(t_list **stack_a, t_list **stack_b)
{
    push_smallest_to_b(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
}

// Ordena uma stack com cinco elementos
void sort_five(t_list **stack_a, t_list **stack_b)
{
    push_smallest_to_b(stack_a, stack_b);
    push_smallest_to_b(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}
