/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 06:17:05 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 05:27:50 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**init_linked_list(t_node **stack_a, char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		if (parsing(split, split[i], i))
		{
			ft_lstadd_back(stack_a, ft_lstnew(my_atoi(split[i])));
			i++;
		}
		else
		{
			write(2, "Error\n", 6);
			ft_lstiter(*stack_a);
			i = 0;
			while (split[i])
				free(split[i++]);
			exit(1);
		}
	}
	return (split);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**save_split_moves()
{
	char *str;
	char *hhh;
	char	*tmp;
	int	i;
	
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
	return (ft_split("hhh" , ' '));
}

void leaks()
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	atexit(leaks);
	int i = 0;
	t_node	*stack_a;
	t_node	*stack_b;
	char	**split;

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
	
	split = save;
	if (split[0])
		free (hhh);
	i = 0;
	while (split[i])
	{
		if (!ft_strcmp(split[i], "pa\n"))
			pa(&stack_a, &stack_b);
		else if (!ft_strcmp(split[i], "pb\n"))
			pb(&stack_a, &stack_b);
		else if (!ft_strcmp(split[i], "ra\n"))
			rotate(&stack_a);
		else if (!ft_strcmp(split[i], "rb\n"))
			rotate(&stack_b);
		else if (!ft_strcmp(split[i], "rr\n"))
			rr(&stack_a, &stack_b);
		else if (!ft_strcmp(split[i], "rra\n"))
			rrotate(&stack_a);
		else if (!ft_strcmp(split[i], "rrb\n"))
			rrotate(&stack_b);
		else if (!ft_strcmp(split[i], "rrr\n"))
			rrr(&stack_a, &stack_b);
		else if (!ft_strcmp(split[i], "sa\n"))
			swap(&stack_a);
		else if (!ft_strcmp(split[i], "sb\n"))
			swap(&stack_b);
		else if (!ft_strcmp(split[i], "ss\n"))
			swap(&stack_b);
		i++;
	}
	if (sorted_checker(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_split(split);
	ft_lstiter(stack_a);
	ft_lstiter(stack_b);
}
