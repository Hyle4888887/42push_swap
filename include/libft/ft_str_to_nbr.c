/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:25:39 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/23 11:28:06 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res > (INT_MAX / 10) || (res == INT_MAX / 10
				&& (*str - '0') > LLONG_MAX % 10))
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		res = res * 10 + (*str++ - '0');
	}
	return (res * sign);
}

double	ft_atod(const char *str)
{
	double	res;
	double	sign;
	double	decimal_place;

	res = 0.0;
	sign = 1.0;
	decimal_place = 1.0;
	while (*str == ' ')
		str++;
	if (*str++ == '-')
		sign = -1.0;
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			decimal_place /= 10.0;
			res += (*str++ - '0') * decimal_place;
		}
	}
	return (res * sign);
}

long long	ft_atoll(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res > (LLONG_MAX / 10) || (res == LLONG_MAX / 10
				&& (*str - '0') > LLONG_MAX % 10))
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		res = res * 10 + (*str++ - '0');
	}
	return (res * ((long long)sign));
}

size_t	ft_atost(const char *str)
{
	size_t	res;

	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (res > (SIZE_MAX / 10) || (res == SIZE_MAX / 10
				&& (unsigned long)(*str - '0') > SIZE_MAX % 10))
			return (SIZE_MAX);
		res = res * 10 + (*str++ - '0');
	}
	return (res);
}
