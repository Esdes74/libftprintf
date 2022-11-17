/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:07:36 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/17 09:43:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_in(const char src, const char *test)
{
	size_t	ind;

	ind = 0;
	while (test[ind] != '\0')
	{
		if (test[ind] == src)
			return (1);
		ind++;
	}
	return (0);
}

void	ft_analyse(const char *src, const char *set, size_t *len, size_t *len_f)
{
	size_t	save_len;

	*len = 0;
	while (ft_in(src[*len], set) == 1)
		(*len)++;
	save_len = *len;
	*len_f = *len;
	while (src[save_len] != '\0')
	{
		if (ft_in(src[save_len], set) == 0)
			*len_f = save_len;
		save_len++;
	}
}

char	*ft_strtrim(const char *src, const char *set)
{
	size_t	begin;
	size_t	end;
	char	*new;

	ft_analyse(src, set, &begin, &end);
	new = ft_substr(src, (unsigned int) begin, end - begin + 1);
	if (new == 0)
		return (0);
	return (new);
}
