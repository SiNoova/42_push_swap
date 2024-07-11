/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 06:17:05 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/11 17:40:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_index(t_node *stack)
{
	int i;

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

void position(t_node *stack)
{
	int size;
	int smol;
	int i ;
	t_node *tmp;

	tmp = stack;
	size = ft_lstsize(stack) - 1;
	i = 0;
	while (tmp)
	{
		tmp->i = 0;
		tmp = tmp->next;
	}
	while (i <= size)
	{
		smol = MAXINT;
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

int empty_str(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int parsing(char **lst, char *str, int j)
{
	int i = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		if (ft_strlen(str) == 1)
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (my_atoi(lst[i]) == my_atoi(str))
			return (0);
		i++;
	}
	return (1);
}

void leaks(void)
{
	system("leaks a.out");
}
int	main(int ac, char **av)
{
	int i = 1;
	char *str = "";
	char *tmp;
	t_node *head = NULL;
	t_node *stack_b = NULL;
	if(ac == 1)
		return (0);
	while (i < ac)
	{
		tmp = str;
		if (empty_str(av[i]))
			str = ft_strjoin(str, av[i]);
		else
		{
			write (1, "Error\n", 7);
			if (i != 1)
			free(tmp);
			exit(1);
		}
		if (i != 1)
			free(tmp);
		i++;
	}
	// printf("%s", str);
	char **split = ft_split(str, ' ');
	free(str);


	i = 0;
	while (split[i])
	{
		if (parsing(split, split[i], i))
		{
			// printf("%s ", split[i]);
			ft_lstadd_back(&head, ft_lstnew(my_atoi(split[i])));
			i++;
		}
		else
		{
			write(1, "Error\n", 7);
			ft_lstiter(head);
			i = 0;
			while (split[i])
			{
				free(split[i]);
				i++;
			}
			exit(1);
		}
	}
	//ft_lstiter(head);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	starter(&head, &stack_b);
	ft_lstiter(head);
}
