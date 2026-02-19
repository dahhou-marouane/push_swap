/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:07:07 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/19 20:15:40 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_atoi(char *str, int *error)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	sign = ft_sign((char *)str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i]
					- '0') > INT_MAX % 10))
		{
			if (sign == 1 || (sign == -1 && str[i] - '0' > (INT_MAX % 10) + 1))
			{
				*error = 1;
				return (0);
			}
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_check_num(char **arn)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (arn[i])
	{
		ft_atoi(arn[i], &error);
		if (error)
		{
			ft_free_split(arn);
			ft_error();
		}
		i++;
	}
}
