/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 06:17:05 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 06:42:56 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_everything(char **split, t_node *stack_a, t_node *stack_b)
{
	free_split(split);
	ft_lstiter(stack_a);
	ft_lstiter(stack_b);
}

char	**save_split_moves(char *str)
{
	char	*hhh;
	char	*tmp;
	char	**split;
	int		i;

	hhh = "";
	str = get_next_line(0);
	i = 0;
	while (str)
	{
		str_pars(str);
		tmp = hhh;
		hhh = ft_strjoin(hhh, str);
		if (i)
			free(tmp);
		free(str);
		str = get_next_line(0);
		i++;
	}
	split = ft_split(hhh, ' ');
	if (split[0])
		free (hhh);
	return (split);
}

void	sort_2(char **split, t_node **stack_a, t_node **stack_b, int i)
{
	if (!ft_strcmp(split[i], "rra\n"))
		rrotate(stack_a);
	else if (!ft_strcmp(split[i], "rrb\n"))
		rrotate(stack_b);
	else if (!ft_strcmp(split[i], "rrr\n"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(split[i], "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(split[i], "sb\n"))
		swap(stack_b);
	else if (!ft_strcmp(split[i], "ss\n"))
		ss(stack_a, stack_b);
}

void	sort(char **split, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!ft_strcmp(split[i], "pa\n"))
			pa(stack_a, stack_b);
		else if (!ft_strcmp(split[i], "pb\n"))
			pb(stack_a, stack_b);
		else if (!ft_strcmp(split[i], "ra\n"))
			rotate(stack_a);
		else if (!ft_strcmp(split[i], "rb\n"))
			rotate(stack_b);
		else if (!ft_strcmp(split[i], "rr\n"))
			rr(stack_a, stack_b);
		sort_2(split, stack_a, stack_b, i);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**split;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	str = fill_str(av, ac);
	split = init_linked_list(&stack_a, str);
	free(str);
	free_split(split);
	if (sorted_checker(stack_a))
	{
		ft_lstiter(stack_a);
		return (0);
	}
	split = save_split_moves(str);
	sort(split, &stack_a, &stack_b);
	if (sorted_checker(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_everything(split, stack_a, stack_b);
}
