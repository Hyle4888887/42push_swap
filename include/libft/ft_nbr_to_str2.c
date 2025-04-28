/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_to_str2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:27:04 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/23 16:54:53 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double num, int decimals)
{
	int		int_part;
	int		i;
	char	*str;
	double	decimal_part;

	str = (char *)malloc(50 * sizeof(char));
	if (!str)
		return (NULL);
	int_part = (int)num;
	decimal_part = num - int_part;
	str = ft_itoa(int_part);
	i = 0;
	while (str[i] != '\0')
		i++;
	str[i++] = '.';
	while (decimals-- > 0)
	{
		decimal_part *= 10;
		str[i++] = ((int)decimal_part) + '0';
		decimal_part -= (int)decimal_part;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_sttoa(size_t nb)
{
	int		size;
	char	*res;

	if (nb >= SIZE_MAX)
		return ((char *)"9223372036854775807");
	size = ft_nbulen(nb, 10);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[size] = '\0';
	while ((--size) > 0)
	{
		res[size] = (nb % 10) + '0';
		nb /= 10;
	}
	if (nb > 0)
		res[size] = nb + '0';
	return (res);
}

// Number in hex, bool: upper_alpha = true; lower_alpha = true
char	*ft_sttohex(size_t nb, bool up)
{
	char	*num;
	int		i;

	if (nb == 0)
		return ("0");
	else if (nb == SIZE_MAX && up)
		return ("FFFFFFFFFFFFFFFF");
	else if (nb == SIZE_MAX && !up)
		return ("ffffffffffffffff");
	i = ft_nbulen(nb, 16);
	num = (char *)malloc((i + 1) * sizeof(char));
	num[i--] = 0;
	while (nb > 0)
	{
		if (up)
			num[i] = ("0123456789ABCDEF")[nb % 16];
		else
			num[i] = ("0123456789abcdef")[nb % 16];
		nb /= 16;
		i--;
	}
	return (num);
}
