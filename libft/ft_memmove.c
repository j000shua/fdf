/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:56:24 by jlinguet          #+#    #+#             */
/*   Updated: 2023/11/13 10:56:29 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;

	src += n - 1;
	p = dest + n - 1;
	while (n)
	{
		*p = *(unsigned char *)src;
		n--;
		p--;
		src--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (dest == src + i)
			return (ft_memrcpy(dest, src, n));
		i++;
	}
	return (ft_memcpy(dest, src, n));
}
