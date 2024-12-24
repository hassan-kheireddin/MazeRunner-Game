/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:28:06 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:04:59 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>

size_t	strlen(const char *s);
char	*strchr(const char *s, int c);
char	*strjoin(char const *s1, char const *s2);
char	*ft_new_line(char *s);
char	*ft_newstr(char *s);
char	*ft_free(char *s, char *buffer);
char	*ft_read(int fd, char *s);
char	*get_next_line(int fd);

#endif
