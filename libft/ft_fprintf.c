/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:04 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/14 15:29:05 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbru_fd(unsigned long nbr, char *base, int fd)
{
	int		len;
	t_uint	base_len;
	char	c;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
			len += ft_putnbru_fd(nbr / base_len, base, fd);
	c = base[nbr % base_len];
	return (ft_putchar_fd(c, fd) + len);
}

static int	conv_p(va_list ap, int fd)
{
	t_ulong	arg;

	arg = va_arg(ap, t_ulong);
	if (!arg)
		return (ft_putstr_fd("(nil)", fd));
	ft_putstr_fd("0x", fd);
	return (2 + ft_putnbru_fd(arg, "0123456789abcdef", fd));
}

static int	print_conv(char c, va_list ap, int fd)
{
	int	len;

	if (c == 'c')
		len = ft_putchar_fd((char)va_arg(ap, int), fd);
	else if (c == 's')
		len = ft_putstr_fd(va_arg(ap, char *), fd);
	else if (c == 'i' || c == 'd')
		len = ft_putnbr_fd(va_arg(ap, int), fd);
	else if (c == 'u')
		len = ft_putnbru_fd(va_arg(ap, t_uint), "0123456789", fd);
	else if (c == 'x')
		len = ft_putnbru_fd(va_arg(ap, t_uint), "0123456789abcdef", fd);
	else if (c == 'X')
		len = ft_putnbru_fd(va_arg(ap, t_uint), "0123456789ABCDEF", fd);
	else if (c == 'p')
		len = conv_p(ap, fd);
	else if (c == '%')
		len = ft_putchar_fd('%', fd);
	else
		len = ft_putchar_fd('%', fd) + ft_putchar_fd(c, fd);
	return (len);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	int		len;
	va_list	ap;

	if (!str)
		return (-1);
	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!*(str + 1))
				return (-1);
			len += print_conv(*(str + 1), ap, fd);
			str += 2;
		}
		else
		{
			ft_putchar_fd(*str, fd);
			str++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	if (!str)
		return (-1);
	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!*(str + 1))
				return (-1);
			len += print_conv(*(str + 1), ap, 1);
			str += 2;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
