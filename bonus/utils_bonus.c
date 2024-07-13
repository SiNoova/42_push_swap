/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:25:48 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 08:04:35 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while ((i < dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

int	sorted_checker(t_node *stack)
{
	while (stack)
	{
		if (stack->next && stack->x > stack->next->x)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	my_atoi(char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		if ((sign == -1 && - nbr < INT_MIN) || (sign != -1 && nbr > INT_MAX))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (nbr * sign);
}

int	empty_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	parsing(char **lst, char *str, int j)
{
	int	i;

	i = 0;
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
