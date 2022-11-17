/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:35:50 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/17 14:04:00 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*beg;
	t_list	*tmp;
	t_list	*new;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	beg = 0;
	tmp = 0;
	while (lst != 0)
	{
		new = ft_lstnew(f(lst->content));
		if (new == 0)
		{
			ft_lstclear(&beg, del);
			return (0);
		}
		if (tmp == 0)
			ft_lstadd_back(&beg, new);
		else
			tmp->next = new;
		lst = lst->next;
	}
	return (beg);
}
