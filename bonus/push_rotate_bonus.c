/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 02:25:28 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 04:13:57 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
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
	}
}

void	rotate(t_node **stack)
{
	t_node	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_lstlast(tmp)->next = tmp;
		tmp->next = NULL;
	}
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
