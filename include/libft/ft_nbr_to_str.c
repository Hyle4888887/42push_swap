/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:52:53 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/23 15:59:41 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	int		size;
	char	*res;

	if (nb >= INT_MAX)
		return ((char *)"2147483647");
	else if (nb <= INT_MIN)
		return ((char *)"-2147483648");
	size = ft_nbrlen((long long)nb, 10);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	while ((--size) > 0)
	{
		res[size] = (nb % 10) + '0';
		nb /= 10;
	}
	if (nb > 0)
		res[size] = nb + '0';
	return (res);
}

char	*ft_lltoa(long long nb)
{
	int		size;
	char	*res;

	if (nb >= LLONG_MAX)
		return ((char *)"9223372036854775807");
	else if (nb <= LLONG_MIN)
		return ((char *)"-9223372036854775808");
	size = ft_nbrlen(nb, 10);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	while ((--size) > 0)
	{
		res[size] = (nb % 10) + '0';
		nb /= 10;
	}
	if (nb > 0)
		res[size] = nb + '0';
	return (res);
}

/*#include <stdio.h>
int	main(void)
{
	int nb = 256410;
	char *str = ft_itoa(nb);
	printf("nb: %i, ft_itoa: %s", nb, str);
	free(str);
	return (0);
}*/
