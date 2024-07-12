/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:59:05 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/12 03:59:37 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
