/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:32:02 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/17 10:53:25 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = ft_sign((char *)str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] == '+' || str[i] == '-')
			ft_error();
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res * sign > 2147483647 || res * sign < -2147483648)
		ft_error();
	return (res * sign);
}
