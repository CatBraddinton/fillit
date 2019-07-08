/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:45:50 by kdudko            #+#    #+#             */
/*   Updated: 2019/01/05 02:44:48 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (len--)
	{
		if (haystack[i] == needle[j] && haystack[i])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)&(haystack[i - j]));
		}
		else if (haystack[i] != needle[j] && haystack[i])
		{
			if (ft_strlen(needle) > 1 && len > 1)
				len = len + j;
			i = i - j + 1;
			j = 0;
		}
	}
	return (NULL);
}
