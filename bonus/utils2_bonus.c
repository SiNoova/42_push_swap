/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 05:12:46 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 06:43:35 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[i] || ss2[i]))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

void	str_pars(char *str)
{
	char	*moves[12];
	int		i;

	i = 0;
	moves[0] = "pa\n";
	moves[1] = "pb\n";
	moves[2] = "ra\n";
	moves[3] = "rb\n";
	moves[4] = "rr\n";
	moves[5] = "rra\n";
	moves[6] = "rrb\n";
	moves[7] = "rrr\n";
	moves[8] = "sa\n";
	moves[9] = "sb\n";
	moves[10] = "ss\n";
	moves[11] = NULL;
	while (moves[i])
	{
		if (ft_strcmp(str, moves[i]))
			i++;
		else
			return ;
	}
	write (1, "Error\n", 6);
	exit(1);
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
