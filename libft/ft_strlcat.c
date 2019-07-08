/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:55:47 by kdudko            #+#    #+#             */
/*   Updated: 2019/01/05 01:22:00 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	j = 0;
	i = 0;
	dst_len = ft_strlen(dst);
	i = dst_len;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize < dst_len + 1)
		return (ft_strlen(src) + dstsize);
	while (src[j] && i < (dstsize - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + ft_strlen(src));
}
