/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ten_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:03:08 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/23 09:05:47 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*calc_len_hex(int nbr, int *len)
{
	char			*new;
	unsigned int	new_nbr;

	if (nbr < 0)
	{
		new_nbr = -nbr;
		(*len)++;
	}
	else
		new_nbr = nbr;
	while (new_nbr > 15)
	{
		new_nbr = new_nbr / 16;
		(*len)++;
	}
	new = (char *) malloc(sizeof(char) * (*len));
	if (new == 0)
		return (0);
	if (nbr < 0)
		new[0] = '-';
	new[*len] = '\0';
	(*len)--;
	return (new);
}

int	conv_ten_to_hex(int nbr, char dep)
{
	char	*res;
	int		len;
	int		mod;

	len = 1;
	res = calc_len_hex(nbr, &len);
	if (res == 0)
		return (0);
	while (nbr > 15)
	{
		len--;
		mod = nbr % 16;
		if (mod > 9)
			res[len] = dep + (mod % 10);
		else
			res[len] = '0' + mod;
		nbr = nbr / 16;
	}
	/* ft_putstr_fd(res, 1); */
	printf("res = |%s|\n", res);
	free(res);
	return (1);
}

int	main(void)
{
	return (0);
}
