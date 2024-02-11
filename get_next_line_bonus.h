/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:06:32 by mohmazou          #+#    #+#             */
/*   Updated: 2024/02/10 22:06:48 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read(char *static_var, int fd);
char	*ft_update(char *static_var);
char	*ft_line(char *static_var);
char	*ft_strjoin(char *s1, char*s2);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);

#endif