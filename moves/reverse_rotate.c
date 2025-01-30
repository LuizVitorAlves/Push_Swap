/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 03:30:35 by lalves-d          #+#    #+#             */
/*   Updated: 2025/01/30 05:23:37 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = *stack;
	end = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = temp;
	(*stack)->next = NULL;
	*stack = end;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
