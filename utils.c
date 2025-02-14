/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 03:01:09 by lalves-d          #+#    #+#             */
/*   Updated: 2025/02/14 01:31:06 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static int	get_smallest_pos(t_list *stack)
{
	t_list	*temp;
	int		smallest;
	int		pos;
	int		i;

	if (!stack)
		return (-1);
	temp = stack;
	smallest = temp->content;
	pos = 0;
	i = 0;
	while (temp)
	{
		if (temp->content < smallest)
		{
			smallest = temp->content;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

void	push_smallest_to_b(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	len;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	len = ft_lstsize(*stack_a);
	pos = get_smallest_pos(*stack_a);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (pos++ < len)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
