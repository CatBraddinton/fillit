/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 07:42:19 by kdudko            #+#    #+#             */
/*   Updated: 2018/12/13 09:27:13 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (*alst && del)
	{
		while ((*alst) != NULL)
		{
			temp = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = temp;
		}
		*alst = NULL;
	}
}
