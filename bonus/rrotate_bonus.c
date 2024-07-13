/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:55:10 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 06:43:27 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrotate(t_node **stack)
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
	}
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
}
