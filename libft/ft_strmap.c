/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:41:58 by kdudko            #+#    #+#             */
/*   Updated: 2018/12/11 07:35:24 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	if (s && f)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s));
		if (str == NULL)
			return (NULL);
		while (*(s + i))
		{
			*(str + i) = f(*(s + i));
			i++;
		}
		*(str + i) = 0;
		return (str);
	}
	return (0);
}
