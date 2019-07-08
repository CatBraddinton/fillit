/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 04:58:45 by kdudko            #+#    #+#             */
/*   Updated: 2018/11/16 05:06:10 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *arr;

	arr = ft_memalloc(size + 1);
	if (arr == 0)
		return (NULL);
	ft_bzero(arr, size + 1);
	return (arr);
}
