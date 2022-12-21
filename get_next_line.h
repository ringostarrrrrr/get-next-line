/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naoki <naoki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:14:38 by naokifuse         #+#    #+#             */
/*   Updated: 2022/12/21 14:47:05 by naoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_about_line(int fd, char *about_line);
char	*get_line(char *str);
char	*get_new_about_line(char *about_line);
char	*get_next_line(int fd);

#endif
