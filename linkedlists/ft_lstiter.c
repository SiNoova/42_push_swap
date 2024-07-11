#include "../push_swap.h"


void ft_lstiter(t_node *node)
{
	t_node *tmp;

	if (!node)
		return ;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}

}