/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:23:30 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/10/10 17:23:32 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_front(char *save)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!save[i])
		return (ft_free(save));
	while (save[i] != '\n' && save[i])
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (ft_free(save));
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		tmp[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		tmp[i] = save[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_back(char *save, char *line)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (line == NULL)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!tmp)
		return (ft_free(save));
	i++;
	while (save[i])
		tmp[j++] = save[i++];
	tmp[j] = '\0';
	free(save);
	return (tmp);
}

void	*ft_free(char *buf)
{
	free(buf);
	return (NULL);
}

void	*ft_free_w(char *save, char *buf)
{
	free(buf);
	free(save);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*save;
	char		*line;
	int			n;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = 1;
	while (!ft_strchr(save, '\n') && n != 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (ft_free_w(save, buf));
		buf[n] = '\0';
		save = ft_strjoin(save, buf);
		if (!save)
			return (ft_free(buf));
	}
	line = ft_front(save);
	save = ft_back(save, line);
	free(buf);
	return (line);
}
