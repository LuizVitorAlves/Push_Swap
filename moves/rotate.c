/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 03:09:05 by lalves-d          #+#    #+#             */
/*   Updated: 2025/01/30 03:21:02 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
static void	rotate(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = temp->next;
	temp->next = NULL;
	ft_lstlast(*stack)->next = temp;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
