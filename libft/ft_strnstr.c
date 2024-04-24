/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:03:52 by jlinguet          #+#    #+#             */
/*   Updated: 2023/11/13 11:03:54 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	little_len;

	if (!little[0])
		return ((char *)big);
	little_len = ft_strlen(little);
	if (!len || little_len > len || little_len > ft_strlen(big))
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		if (little_len > len - i)
			return (NULL);
		if (big[i] == little[0])
		{
			if (!ft_strncmp((char *)&big[i], little, little_len))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
