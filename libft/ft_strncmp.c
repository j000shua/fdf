/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:03:25 by jlinguet          #+#    #+#             */
/*   Updated: 2023/11/15 08:27:54 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (!n)
		return (0);
	i = 0;
	while ((t_uchar)s1[i] == (t_uchar)s2[i] && (t_uchar)s2[i] && i < n - 1)
		i++;
	return ((t_uchar)s1[i] - (t_uchar)s2[i]);
}
