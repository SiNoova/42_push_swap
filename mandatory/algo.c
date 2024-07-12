/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 02:44:20 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/12 05:10:11 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_2(t_node **stack)
{
	if (ft_lstsize(*stack) == 2)
	{
		if ((*stack)->x > (*stack)->next->x)
			rotate(stack, 'a');
	}
	else
	{
		if ((*stack)->x > (*stack)->next->x)
			swap(stack, 'a');
		if ((*stack)->next->x > (*stack)->next->next->x)
			rrotate(stack, 'a');
		if ((*stack)->x > (*stack)->next->x)
			swap(stack, 'a');
	}
}

void	sort_4_5(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		size;
	t_node	*tmp;

	i = 0;
	if (ft_lstsize(*stack_a) == 4)
		size = 1;
	else
		size = 2;
	while (i < size)
	{
		tmp = *stack_a;
		set_index(*stack_a);
		while (tmp->pos != i)
			tmp = tmp->next;
		rotate_and_push(stack_a, tmp, 'a');
		pb(stack_a, stack_b);
		i++;
	}
	sort_3_2(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sorter(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		i;
	int		size;

	position(*stack_b);
	size = ft_lstsize(*stack_b);
	i = size - 1;
	while (i >= 0)
	{
		size = ft_lstsize(*stack_b);
		set_index(*stack_b);
		tmp = *stack_b;
		while (tmp->pos != i)
			tmp = tmp->next;
		rotate_and_push(stack_b, tmp, 'b');
		pa(stack_a, stack_b);
		i--;
	}
}

void	algo(t_node **stack_a, t_node **stack_b, int size)
{
	int		i;
	int		x;

	i = 0;
	if (size <= 100)
		x = 16;
	else
		x = 34;
	while (*stack_a)
	{
		if ((*stack_a)->pos <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->pos <= x + i)
		{
			pb(stack_a, stack_b);
			rotate(stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a');
	}
	sorter(stack_a, stack_b);
}

void	starter(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		size;

	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	position(*stack_a);
	if (sorted_checker(*stack_a))
		return ;
	if (size == 1)
		return ;
	else if (size == 2 || size == 3)
		sort_3_2(stack_a);
	else if (size == 4 || size == 5)
		sort_4_5(stack_a, stack_b);
	else
		algo(stack_a, stack_b, size);
}
