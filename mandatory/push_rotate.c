/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 02:25:28 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/12 03:56:14 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		write(1, "pb\n", 3);
	}
}

void	rotate(t_node **stack, char c)
{
	t_node	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_lstlast(tmp)->next = tmp;
		tmp->next = NULL;
		if (c == 'a')
			write (1, "ra\n", 3);
		else if (c == 'b')
			write (1, "rb\n", 3);
	}
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a, '3');
	rotate(stack_b, '3');
	write(1, "rr\n", 3);
}
