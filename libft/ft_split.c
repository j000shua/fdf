/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:37 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/02 19:38:21 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *s, char sep)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || !s[i + 1]))
			n++;
		i++;
	}
	return (n);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		itab;
	int		len;

	tab = ft_calloc((ft_count_words((char *)s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	itab = -1;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			tab[++itab] = ft_substr(s, i - len + 1, len);
			if (tab[itab] == NULL)
				return (free_tab(tab), NULL);
			len = 0;
		}
		i++;
	}
	return (tab);
}
