/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 02:37:13 by kdudko            #+#    #+#             */
/*   Updated: 2018/12/26 15:59:41 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	unsigned long int	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\f') \
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == ' ')))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res >= 922337203685477580 && sign == 1)
			return (-1);
		else if (res > 922337203685477580 && sign == -1)
			return (0);
		i++;
	}
	return ((int)(res * sign));
}
