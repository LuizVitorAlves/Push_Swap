/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:48:27 by lalves-d          #+#    #+#             */
/*   Updated: 2025/02/14 02:11:41 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	while (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
	while (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
	}
}

static void	select_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sort_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

/*static void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("Value: %d, Index: %d\n", stack->content, stack->index);
		stack = stack->next;
	}
}*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_args(&stack_a, argv + 1))
	{
		write(2, "Error\n", 6);
		free_stacks(&stack_a, &stack_b);
		return (1);
	}
	index_stack(stack_a);
	if (is_sorted(stack_a))
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	select_sort(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
