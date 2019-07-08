/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 04:44:52 by kdudko            #+#    #+#             */
/*   Updated: 2018/11/28 00:54:04 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*arr;

	arr = (unsigned char *)malloc(size * sizeof(*arr));
	if (arr == 0)
		return (NULL);
	ft_bzero(arr, size);
	return (arr);
}
