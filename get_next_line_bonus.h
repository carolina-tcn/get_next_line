/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:09:25 by ctacconi          #+#    #+#             */
/*   Updated: 2024/03/11 16:13:53 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
