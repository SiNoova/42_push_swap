/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:59:05 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 06:42:44 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_lstiter(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return ;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}
