#include "pushswap.h"

// Conta quantos elementos existem na stack
t_static int stack_size(t_list *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

// Copia os valores da stack para um array
static int *copy_stack_to_array(t_list *stack, int size)
{
    int *array = malloc(sizeof(int) * size);
    int i = 0;
    if (!array)
        return NULL;
    while (stack)
    {
        array[i++] = stack->content;
        stack = stack->next;
    }
    return array;
}

// Ordena o array usando Bubble Sort (poderia ser QuickSort, mas para poucos elementos está ok)
static void sort_array(int *array, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Converte os números para seus índices
static int get_index(int *array, int size, int value)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1; // Nunca deveria acontecer
}

// Substitui os valores da stack pelos índices ordenados
void index_stack(t_list *stack)
{
    int size = stack_size(stack);
    int *array = copy_stack_to_array(stack, size);
    if (!array)
        return;
    sort_array(array, size);
    while (stack)
    {
        stack->content = get_index(array, size, stack->content);
        stack = stack->next;
    }
    free(array);
}
