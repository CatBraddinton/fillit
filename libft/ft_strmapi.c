/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:01 by kdudko            #+#    #+#             */
/*   Updated: 2018/11/27 18:45:52 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			*(str + i) = f(i, *(s + i));
			i++;
		}
		*(str + i) = '\0';
		return (str);
	}
	return (0);
}
