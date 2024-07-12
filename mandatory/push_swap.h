/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 06:14:32 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/12 04:49:49 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAXINT 2147483647

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				x;
	int				pos;
	int				index;
	int				i;
	struct s_node	*next;
}	t_node;

int		my_atoi(char *str);
t_node	*ft_lstnew(int x);
void	ft_lstadd_back(t_node **lst, t_node *new);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
void	ft_lstiter(t_node *node);
int		ft_lstsize(t_node *lst);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
t_node	*ft_lstlast(t_node *lst);
void	rotate(t_node **stack, char c);
void	swap(t_node **stack, char c);
void	ss(t_node **stack_a, t_node **stack_b);
void	rrotate(t_node **stack, char c);
void	rrr(t_node **stack_a, t_node **stack_b);
int		sorted_checker(t_node *stack);
void	starter(t_node **stack_a, t_node **stack_b);
void	position(t_node *stack);
void	set_index(t_node *stack);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		empty_str(char *str);
int		parsing(char **lst, char *str, int j);
void	put_position(t_node *stack, t_node *tmp, int smol, int size);
void	set_index(t_node *stack);
void	rotate_and_push(t_node **stack_a, t_node *tmp, char c);
#endif