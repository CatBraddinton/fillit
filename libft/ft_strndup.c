/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 03:47:59 by kdudko            #+#    #+#             */
/*   Updated: 2019/01/05 07:25:53 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*copy_str;
	size_t		i;

	i = 0;
	copy_str = (char *)malloc((n + 1) * sizeof(char));
	if (copy_str == NULL)
		return (NULL);
	while (n--)
	{
		copy_str[i] = s1[i];
		i++;
	}
	copy_str[i] = '\0';
	return (copy_str);
}
