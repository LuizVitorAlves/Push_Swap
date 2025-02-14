/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:03:37 by lalves-d          #+#    #+#             */
/*   Updated: 2025/02/14 01:22:34 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_to_stack(t_list **stack, int value)
{
	t_list	*new;
	t_list	*temp;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		exit_error(stack, NULL);
	new->content = value;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	parse_args(t_list **stack_a, char **argv)
{
	int	num;

	while (*argv)
	{
		if (!is_valid_number(*argv))
			return (0);
		num = ft_atoi(*argv, stack_a);
		add_to_stack(stack_a, num);
		argv++;
	}
	if (has_duplicates(*stack_a))
		return (0);
	return (1);
}
