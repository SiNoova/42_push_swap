/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:06:13 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 06:42:50 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_node	*ft_lstnew(int x)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->x = x;
	new_node->index = -1;
	new_node->i = -1;
	new_node->pos = 0;
	new_node->next = NULL;
	return (new_node);
}
