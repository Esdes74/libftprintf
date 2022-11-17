/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:11:32 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/17 10:25:09 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == 0 || *lst == 0)
		return ;
	tmp = *lst;
	if (tmp->next == 0)
		ft_lstdelone(tmp, del);
	else
	{
		ft_lstclear(&(tmp->next), del);
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}
