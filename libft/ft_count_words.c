/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 05:44:30 by kdudko            #+#    #+#             */
/*   Updated: 2018/12/26 16:09:38 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
			while (s[i] != c)
			{
				i++;
				if (s[i] == c)
					words++;
				else if (s[i] == '\0')
					return (words + 1);
			}
	}
	return (words);
}
