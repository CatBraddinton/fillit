/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:36:17 by kdudko            #+#    #+#             */
/*   Updated: 2019/01/08 13:51:04 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;
	t_list *temp;

	head = NULL;
	if (!(lst && f))
		return (NULL);
	temp = f(lst);
	new = ft_lstnew(temp->content, temp->content_size);
	if (new)
	{
		head = new;
		while (lst->next != NULL)
		{
			temp = f(lst->next);
			new->next = ft_lstnew(temp->content, temp->content_size);
			if (new->next)
			{
				lst = lst->next;
				new = new->next;
			}
		}
	}
	return (head);
}
