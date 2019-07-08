/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:51:54 by kdudko            #+#    #+#             */
/*   Updated: 2018/11/15 19:01:26 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(needle) == 1)
		return (ft_strchr(haystack, (int)needle[j]));
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j + 1]);
		}
		i++;
		if (haystack[i] != needle[j] && haystack[i])
		{
			i = i - j + 1;
			j = 0;
		}
	}
	return (NULL);
}
