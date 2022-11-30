/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:09:52 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/30 19:08:57 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static int	print_unsigned(int nbr, int fd)
{
	unsigned int	u_nbr;
	size_t			len;

	u_nbr = nbr;
	len = 0;
	if (u_nbr > 0)
	{
		len += print_unsigned(u_nbr / 10, fd);
		len += ft_putchar_fd('0' + u_nbr % 10, fd);
	}
	return (len);
}

static void	following_is_format(const char *s, int i, va_list *args, int *res)
{
	unsigned int	u_nbr;
	int				i_nbr;

	if (s[i + 1] == 'u')
		(*res) += print_unsigned(va_arg(*args, int), 1);
	if (s[i + 1] == 'x')
		conv_ten_to_hex(va_arg(*args, int), 'a', res);
	if (s[i + 1] == 'X')
		conv_ten_to_hex(va_arg(*args, int), 'A', res);
}

static int	is_format(const char *s, size_t i, va_list *args, int *res)
{
	if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's' || s[i + 1] == 'p' \
				|| s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u' \
				|| s[i + 1] == 'x' || s[i + 1] == 'X' || s[i + 1] == '%'))
	{
		if (s[i + 1] == 'c')
			(*res) += ft_putchar_fd(va_arg(*args, int), 1);
		else if (s[i + 1] == 's')
			(*res) += ft_putstr_fd(va_arg(*args, char *), 1);
		else if (s[i + 1] == 'p')
			print_adress(va_arg(*args, long long unsigned int), 'a', res, 1);
		else if (s[i + 1] == 'd')
			(*res) += ft_putnbr_fd(va_arg(*args, int), 1);
		else if (s[i + 1] == 'i')
			(*res) += ft_putnbr_fd(va_arg(*args, int), 1);
		else if (s[i + 1] == '%')
			(*res) += ft_putchar_fd('%', 1);
		following_is_format(s, i, args, res);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	ind;
	va_list	args;
	int		format;
	int		res;

	ind = 0;
	res = 0;
	va_start(args, str);
	while (str[ind] != '\0')
	{
		format = is_format(str, ind, &args, &res);
		if (str[ind] == '%' && format == 1)
			ind++;
		else if (format == -1)
			return (res);
		else
			res += ft_putchar_fd(str[ind], 1);
		ind++;
	}
	va_end(args);
	return (res + 15);
}
