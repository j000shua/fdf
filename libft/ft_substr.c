/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:04:47 by jlinguet          #+#    #+#             */
/*   Updated: 2023/11/17 08:26:32 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (ft_strlen(s) < start)
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (ft_strlen(&s[start]) < len)
		substr = ft_calloc((ft_strlen(&s[start]) + 1), sizeof(char));
	else
		substr = ft_calloc((len + 1), sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	return (substr);
}
