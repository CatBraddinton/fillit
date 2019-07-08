/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 01:22:14 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/03 14:50:45 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc(char **arr, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	len;
	size_t	row;

	i = 0;
	row = 0;
	while (s[i] && row < words)
	{
		len = 0;
		while (s[i] != c)
		{
			len++;
			i++;
			if (s[i] == c)
			{
				i = i - len;
				arr[row] = ft_strsub(s, i, (size_t)len);
				i = i + len;
				row++;
			}
		}
		i++;
	}
	arr[row] = 0;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**arr;

	if (!(s && c))
		return (NULL);
	words = ft_count_words(s, c);
	arr = (char **)malloc(sizeof(char*) * (words + 1));
	if (arr == NULL)
		return (NULL);
	if (ft_strlen(s) > 1 && ft_strchr(s, c) == NULL)
	{
		arr[0] = ft_strsub(s, 0, ft_strlen(s));
		arr[1] = 0;
		return (arr);
	}
	arr = alloc(arr, s, c, words);
	return (arr);
}
