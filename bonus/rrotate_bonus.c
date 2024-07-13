/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:55:10 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/12 04:01:01 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_node **stack, char c)
{
	t_node	*second_last;
	t_node	*last_node;

	if (*stack && ft_lstsize(*stack) > 1)
	{
		second_last = *stack;
		last_node = ft_lstlast(*stack);
		while (second_last->next != last_node)
			second_last = second_last->next;
		second_last->next = NULL;
		last_node->next = *stack;
		*stack = last_node;
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrotate(stack_a, '2');
	rrotate(stack_b, '2');
	write(1, "rrr\n", 4);
}
