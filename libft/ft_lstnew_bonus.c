/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:22:31 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/17 14:05:09 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *new_content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->next = 0;
	new->content = new_content;
	return (new);
}
