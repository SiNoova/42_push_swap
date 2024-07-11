/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:35:24 by akoutate          #+#    #+#             */
/*   Updated: 2024/06/28 18:59:03 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!lst)
		return ;
	t_node *temp = *lst;
	
	while(temp->next)
		temp = temp->next;
	temp->next = new;
}