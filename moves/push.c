/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:52:31 by lalves-d          #+#    #+#             */
/*   Updated: 2025/01/30 02:16:04 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = temp;
	ft_putstr_fd("pb\n", 1);
}
