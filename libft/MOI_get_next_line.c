/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:10:45 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/07 12:00:08 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_up(char *buf, char **line)
{
	char	*end;
	size_t	i;
	size_t	j;

	*line = NULL;
	end = ft_strchr(buf, '\n');
	if (!end)
		return (1);
	i = 0;
	while (&buf[i] != end)
		i++;
	*line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (0);
	ft_strlcpy(*line, buf, i + 2);
	j = 0;
	while (++i < BUFFER_SIZE && buf[i])
		buf[j++] = buf[i];
	buf[j] = '\0';
	return (1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc((len1 + len2 + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		s[i++] = s2[j++];
	s[i] = '\0';
	return (free(s1), s);
}

int	reading(size_t *nbr, int *fd, char *buf, char **line)
{
	while (*nbr && !ft_strchr(buf, '\n'))
	{
		buf[*nbr] = '\0';
		*line = ft_strjoin_gnl(*line, buf);
		if (!*line)
			return (0);
		*nbr = read(*fd, buf, BUFFER_SIZE);
	}
	return (1);
}

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	size_t		nbr;

	if (read(fd, buf, 0) < 0 || !set_up(buf, &line))
		return (printf("oy1"),NULL);
	if (line)
		return (printf("oy2"),line);
	line = ft_strdup(buf);
	if (!line)
		return (printf("oy3"),NULL);
	nbr = read(fd, buf, BUFFER_SIZE);
	
	if (!reading(&nbr, &fd, buf, &line))
		return (printf("oy4"),NULL);
	printf("buf = __%s__\n", buf);
	if (!nbr && buf[0])
		return (ft_bzero(buf, 1),printf("oy5"), line);
	if (!nbr)
		return (free(line),printf("oy6"), NULL);
	buf[nbr] = 0;
	if (!set_up(buf, &tmp))
		return (printf("oy7"),NULL);
	line = ft_strjoin_gnl(line, tmp);
	return (free(tmp), line);
}
