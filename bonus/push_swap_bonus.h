/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 06:14:32 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 05:13:59 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define BUFFER_SIZE 5

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

		// linkedlist funcs

t_node	*ft_lstnew(int x);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstiter(t_node *node);
int		ft_lstsize(t_node *lst);

		// utils

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		my_atoi(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);

		// moves 

void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack);
void	swap(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);
void	rrotate(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

		// parsing

int		empty_str(char *str);
int		parsing(char **lst, char *str, int j);
int		sorted_checker(t_node *stack);
		// get_next_line funcs

char	*get_next_line(int fd);
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen_g(const char *s, int a);

int		ft_strcmp(const char *s1, const char *s2);
void 	str_pars(char *str);
char	*fill_str(char **av, int ac);

#endif