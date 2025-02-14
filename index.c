/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:29:23 by lalves-d          #+#    #+#             */
/*   Updated: 2025/02/13 22:17:34 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static int	*copy_stack_to_array(t_list *stack, int size)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	i = 0;
	if (!array)
		return (NULL);
	while (stack)
	{
		array[i++] = stack->content;
		stack = stack->next;
	}
	return (array);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	get_index(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_list *stack)
{
	int		size;
	int		*array;

	size = stack_size(stack);
	array = copy_stack_to_array(stack, size);
	if (!array)
		return ;
	sort_array(array, size);
	while (stack)
	{
		stack->index = get_index(array, size, stack->content);
		stack = stack->next;
	}
	free(array);
}
