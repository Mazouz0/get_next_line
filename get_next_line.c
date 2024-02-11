/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 06:16:57 by mohmazou          #+#    #+#             */
/*   Updated: 2024/02/11 23:31:52 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_var;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	static_var = ft_read(static_var, fd);
	if (!static_var)
		return (NULL);
	line = ft_line(static_var);
	static_var = ft_update(static_var);
	return (line);
}

char	*ft_read(char *static_var, int fd)
{
	char	*buffer;
	int		readed;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (readed > 0 && !ft_strchr(static_var, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			free(static_var);
			return (buffer = NULL, static_var = NULL, NULL);
		}
		buffer[readed] = '\0';
		static_var = ft_strjoin(static_var, buffer);
		if (!static_var)
			return (NULL);
	}
	free(buffer);
	return (static_var);
}

char	*ft_line(char *static_var)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (static_var[i] == '\0' || !static_var)
		return (NULL);
	while (static_var[i] && static_var[i] != '\n')
		i ++;
	if (static_var[i] == '\n')
		i ++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = static_var[j];
		j ++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_update(char *static_var)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	if (static_var[i] == '\0' || !static_var)
		return (free(static_var), static_var = NULL, NULL);
	while (static_var[i] && static_var[i] != '\n')
		i ++;
	if (static_var[i] == '\n')
		i ++;
	new = (char *)malloc(ft_strlen(static_var) - i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (static_var[i])
	{
		new[j] = static_var[i];
		i ++;
		j ++;
	}
	new[j] = '\0';
	free(static_var);
	return (static_var = NULL, new);
}
