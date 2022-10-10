/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:23:18 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/10/10 17:23:20 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_front(char *save);
char	*ft_back(char *save, char *line);
char	*get_next_line(int fd);
void	*ft_free(char *buf);
void	*ft_free_w(char *save, char *buf);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, size_t c);
char	*ft_strjoin(char *s1, char *s2);

#endif
