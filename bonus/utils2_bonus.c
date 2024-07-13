/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:35:06 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 00:25:01 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	put_position(t_node *stack, t_node *tmp, int smol, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		smol = INT_MAX;
		tmp = stack;
		while (tmp)
		{
			if (tmp->x <= smol && tmp->i == 0)
				smol = tmp->x;
			tmp = tmp->next;
		}
		tmp = stack;
		while (tmp)
		{
			if (tmp->x == smol)
			{
				tmp->i = 1;
				tmp->pos = i;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

void	rotate_and_push(t_node **stack, t_node *tmp, char c)
{
	if (tmp->index <= ft_lstsize(*stack) / 2)
	{
		while ((*stack)->x != tmp->x)
			rotate(stack, c);
	}
	else
	{
		while ((*stack)->x != tmp->x)
			rrotate(stack, c);
	}
}
