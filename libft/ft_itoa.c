/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 02:22:15 by kdudko            #+#    #+#             */
/*   Updated: 2018/12/20 12:11:50 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*s;
	unsigned int	nb;
	size_t			len;

	nb = n;
	len = n_len(n);
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = nb % 10 + '0';
	while (nb /= 10)
		s[--len] = nb % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}
