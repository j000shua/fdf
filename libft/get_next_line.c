/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:04:44 by stouitou          #+#    #+#             */
/*   Updated: 2024/05/07 12:02:47 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_initstr(char *str)
{
	if (str == NULL)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}

char	*ft_get_line(int fd, char *str, char *buffer)
{
	int		got;
	char	*tmp;

	if (str)
	{
		if (ft_ischarset(str, '\n'))
			return (str);
	}
	got = 1;
	while (got)
	{
		got = read(fd, buffer, BUFFER_SIZE);
		if (got < 0)
			return (NULL);
		if (got == 0)
			break ;
		buffer[got] = '\0';
		str = ft_initstr(str);
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_ischarset(buffer, '\n'))
			break ;
	}
	return (str);
}

char	*ft_get_more(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	tmp = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (tmp[0] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	str[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = ft_get_line(fd, stash, buffer);
	free(buffer);
	if (line == NULL)
		return (NULL);
	stash = ft_get_more(line);
	return (line);
}
