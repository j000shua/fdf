/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:13 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/14 15:16:31 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int nbr, int fd)
{
	int		len;
	char	c;

	if (nbr == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > 9)
		len += ft_putnbr_fd(nbr / 10, fd);
	c = nbr % 10 + '0';
	return (ft_putchar_fd(c, fd) + len);
}
