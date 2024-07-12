/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:54:03 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/12 03:54:35 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack, char c)
{
	int	tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = (*stack)->x;
		(*stack)->x = (*stack)->next->x;
		(*stack)->next->x = tmp;
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'b')
			write(1, "sb\n", 3);
	}
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a, '1');
	swap(stack_b, '1');
	write(1, "ss\n", 3);
}
