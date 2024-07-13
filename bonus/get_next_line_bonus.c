/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:03:45 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/13 06:43:07 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*fill_strr(char *line, char **str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp1;

	i = ft_strlen_g(line, '\n');
	j = ft_strlen_g(line, '\0');
	tmp = line;
	line = ft_substr(line, 0, i + 1);
	tmp1 = *str;
	*str = ft_substr(tmp, i + 1, j - i - 1);
	if (!*str[0])
	{
		free(*str);
		*str = NULL;
	}
	free (tmp);
	free (tmp1);
	return (line);
}

char	*fill_line(int fd, char *buffer, char *line, char **str)
{
	int		x;
	char	*tmp;

	while (1)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (!x)
		{
			if (line)
				return (tmp = line, line = NULL, tmp);
			return (NULL);
		}
		buffer[x] = '\0';
		tmp = line;
		line = ft_strjoin_g(line, buffer);
		free (tmp);
		if (ft_strrchr(line, '\n'))
		{
			line = fill_strr(line, str);
			break ;
		}
	}
	return (line);
}

char	*str_free(int fd, char **str, char *buffer)
{
	char	*line;

	line = ft_strjoin_g(*str, "");
	if (ft_strrchr(line, '\n'))
		return (fill_strr(line, str));
	free (*str);
	*str = NULL;
	return (fill_line(fd, buffer, line, str));
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buffer;
	char		*line;

	line = NULL;
	if (fd >= 0 && fd < OPEN_MAX
		&& BUFFER_SIZE > 0 && BUFFER_SIZE <= INT_MAX)
	{
		buffer = malloc((size_t)BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		if (read(fd, buffer, 0))
		{
			free (str[fd]);
			str[fd] = NULL;
		}
		else if (str[fd])
			line = str_free(fd, &str[fd], buffer);
		else
			line = fill_line(fd, buffer, line, &str[fd]);
		free (buffer);
	}
	return (line);
}
