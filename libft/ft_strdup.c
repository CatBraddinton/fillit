/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:01:11 by kdudko            #+#    #+#             */
/*   Updated: 2018/11/13 15:16:45 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy_str;

	copy_str = (char*)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (copy_str == NULL)
		return (NULL);
	return (ft_strcpy(copy_str, s1));
}
