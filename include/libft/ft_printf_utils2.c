/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:11:38 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/23 18:20:44 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(long nb, bool up, char **str)
{
	int	size;

	if (nb >= LONG_MAX && up)
		return (ft_prints((char *)"7FFFFFFFFFFFFFFF", str));
	else if (nb >= LONG_MAX && !up)
		return (ft_prints((char *)"7fffffffffffffff", str));
	if (nb < 0)
	{
		size = ft_strlen((const char *)(*str));
		(*str) = (char *)ft_realloc((void *)(*str), size + 1);
		(*str)[size] = '-';
		nb = -nb;
	}
	return (ft_prints(ft_sttohex((size_t)nb, up), str));
}

int	ft_printb(int ibool, char **str)
{
	if (ibool == 1)
		return (ft_prints((char *)"true", str));
	else if (ibool == 0)
		return (ft_prints((char *)"false", str));
	else
		return(ft_prints((char *)"error_bool", str));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	size;
	int	i;
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	size = ft_strlen(str);
	i = 0;
	count = 0;
	while (i < size)
		count += ft_putchar((char)str[i++]);
	return (count);
}
