/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ten_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:03:08 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/30 18:09:44 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_adress(long long int nbr, char dep, int *res, int mod)
{
	long long unsigned int	u_nbr;

	if (mod == 1)
		(*res) += ft_putstr_fd("0x", 1);
	u_nbr = nbr;
	if (u_nbr > 0)
	{
		print_adress(u_nbr / 16, dep, res, 0);
		u_nbr = u_nbr % 16;
		if (u_nbr > 9)
			(*res) += ft_putchar_fd(dep + u_nbr % 10, 1);
		else
			(*res) += ft_putchar_fd('0' + u_nbr, 1);
	}
}

void	conv_ten_to_hex(int nbr, char dep, int *res)
{
	unsigned int	u_nbr;

	u_nbr = nbr;
	if (u_nbr > 0)
	{
		conv_ten_to_hex(u_nbr / 16, dep, res);
		u_nbr = u_nbr % 16;
		if (u_nbr > 9)
			(*res) += ft_putchar_fd(dep + u_nbr % 10, 1);
		else
			(*res) += ft_putchar_fd('0' + u_nbr, 1);
	}
}
/* static char	*calc_len_hex(int nbr, int *len) */
/* { */
/* 	char			*new; */
/* 	unsigned int	new_nbr; */

/* 	new_nbr = nbr; */
/* 	while (new_nbr > 15) */
/* 	{ */
/* 		new_nbr = new_nbr / 16; */
/* 		(*len)++; */
/* 	} */
/* 	new = (char *) malloc(sizeof(char) * ((*len) + 1)); */
/* 	if (new == 0) */
/* 		return (0); */
/* 	new[*len] = '\0'; */
/* 	(*len)--; */
/* 	return (new); */
/* } */

/* int	conv_ten_to_hex(int nbr, char dep, int *res) */
/* { */
/* 	char			*new; */
/* 	int				len; */
/* 	int				mod; */
/* 	long long unsigned int	n; */

/* 	len = 1; */
/* 	new = calc_len_hex(nbr, &len); */
/* 	n = nbr; */
/* 	if (new == 0) */
/* 		return (0); */
/* 	while (n > 15 || len == 0) */
/* 	{ */
/* 		mod = n % 16; */
/* 		if (mod > 9) */
/* 			new[len] = dep + (mod % 10); */
/* 		else */
/* 			new[len] = '0' + mod; */
/* 		n = n / 16; */
/* 		len--; */
/* 	} */
/* 	(*res) += ft_putstr_fd(new, 1); */
/* 	free(new); */
/* 	new = 0; */
/* 	return (1); */
/* } */

/* /1* int	main(void) *1/ */
/* /1* { *1/ */
/* /1* 	return (0); *1/ */
/* /1* } *1/ */
