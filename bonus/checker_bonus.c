/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 06:17:05 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/12 05:11:04 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position(t_node *stack)
{
	t_node	*tmp;
	int		size;
	int		smol;

	tmp = stack;
	smol = 0;
	size = ft_lstsize(stack) - 1;
	while (tmp)
	{
		tmp->i = 0;
		tmp = tmp->next;
	}
	put_position(stack, tmp, smol, size);
}

char	*fill_str(char **av, int ac)
{
	char	*str;
	char	*tmp;
	int		i;

	str = "";
	i = 1;
	while (i < ac)
	{
		tmp = str;
		if (empty_str(av[i]))
			str = ft_strjoin(str, av[i]);
		else
		{
			write (2, "Error\n", 6);
			if (i != 1)
				free(tmp);
			exit(1);
		}
		if (i != 1)
			free(tmp);
		i++;
	}
	return (str);
}

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
	starter(&stack_a, &stack_b);
	ft_lstiter(stack_a);
}
