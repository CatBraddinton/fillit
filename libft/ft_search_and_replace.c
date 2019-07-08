/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:34:52 by kdudko            #+#    #+#             */
/*   Updated: 2019/01/08 22:34:58 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_search_and_replace(char *str, char search, char replace)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = ft_strnew(ft_strlen(str));
	if (arr == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == search)
			arr[i] = replace;
		else
			arr[i] = str[i];
		i++;
	}
	return (arr);
}
