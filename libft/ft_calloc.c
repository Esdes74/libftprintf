/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:45:53 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/14 13:54:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void					*new;
	long long unsigned int	len;
	long long unsigned int	tot;

	len = 0;
	tot = size * nbr;
	new = malloc(tot);
	if (new == 0)
		return (0);
	while (len < tot)
	{
		((unsigned char *)new)[len] = 0;
		len++;
	}
	return (new);
}