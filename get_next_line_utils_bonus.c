/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 06:16:59 by mohmazou          #+#    #+#             */
/*   Updated: 2024/02/11 23:18:03 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	l;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	l = ft_strlen(src);
	p = (char *)malloc(l + 1);
	if (!p)
		return (NULL);
	while (src[i])
	{
		p[i] = src[i];
		i ++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_return;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	str_return = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_return)
		return (free(s1), s1 = NULL, NULL);
	while (s1[i])
		str_return[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str_return[j++] = s2[i++];
	str_return[j] = '\0';
	free(s1);
	return (s1 = NULL, str_return);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (*(str + i) != (char)c)
	{
		if (*(str + i) == '\0')
			return (0);
		i ++;
	}
	return (str + i);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}
