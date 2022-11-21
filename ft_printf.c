/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:09:52 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/21 16:59:21 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

int	is_format(const char c, size_t *ind, va_list *args)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
			|| c == 'x' || c == 'X' || c == '%')
	{
		if (c == 'c')
			ft_putchar_fd(va_arg(*args, int), 1);
		else if (c == 's')
			ft_putstr_fd(va_arg(*args, char *), 1);
		else if (c == 'p')
			ft_putnbr_fd(va_arg(*args, int), 1);
		else if (c == 'd')
			ft_putnbr_fd(va_arg(*args, int), 1);
		else if (c == 'i')
			ft_putnbr_fd(va_arg(*args, int), 1);
		else if (c == '%')
		{
			va_arg(*args, int);
			ft_putchar_fd('%', 1);
		}
		(*ind)++;
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	ind;
	va_list	args;

	ind = 0;
	va_start(args, str);
	while (str[ind] != '\0')
	{
		if (str[ind] == '%' && is_format(str[ind + 1], &ind, &args) == 1);
		else
			ft_putchar_fd(str[ind], 1);
		ind++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	int		n;

	n = 124;
	printf("sdgsfh|%d|bsovud|%s|shvyh|%c|bsquygheig|%i|hfd%%\n", n, "little", n, n);
	ft_printf("sdgsfh|%d|bsovud|%s|shvyh|%c|bsquygheig|%i|hfd%%\n", n, "little", n, n);
	printf("sdgsfh|%d|bsovud|%s|shvyh|%c|bsquygheig|%i|hfd%%\n", n, "little", n, n);
}
