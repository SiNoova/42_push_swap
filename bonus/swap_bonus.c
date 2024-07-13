/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:54:03 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 04:16:37 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_node **stack)
{
	int	tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = (*stack)->x;
		(*stack)->x = (*stack)->next->x;
		(*stack)->next->x = tmp;
	}
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
