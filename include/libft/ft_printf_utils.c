/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:14:11 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/25 14:16:28 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(int c, char **str)
{
	int		size;

	size = ft_strlen((const char *)(*str));
	(*str) = (char *)ft_realloc((void *)(*str), (size + 2));
	(*str)[size] = c;
	(*str)[size + 1] = '\0';
	return (size + 2);
}

int	ft_printi(int nb, char **str)
{
	return (ft_prints(ft_itoa(nb), str));
}

int	ft_printu(unsigned int nu, char **str)
{
	if (nu >= UINT_MAX)
		return (ft_prints(ft_sttoa((size_t)UINT_MAX), str));
	return (ft_prints(ft_sttoa((size_t)nu), str));
}

int	ft_printp(void *ptr, char **str)
{
	unsigned long	addr;
	int				size_s;

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (ft_prints((char *)"(nil)", str));
	size_s = ft_strlen((const char *)(*str));
	(*str) = (char *)ft_realloc((void *)(*str), size_s + 2);
	(*str)[size_s] = '0';
	(*str)[size_s] = 'x';
	return (ft_prints(ft_sttohex((size_t)addr, false), str));
}

int	ft_prints(char *s, char **str)
{
	int		size;
	int		size_s;
	int		i;

	size = ft_strlen((const char *)(*str));
	if (!s)
		return (ft_prints((char *)"(null)", str));
	else if (s[0] == '\0')
		return (size);
	size_s = ft_strlen((const char *)s);
	(*str) = (char *)ft_realloc((void *)(*str), (size_t)(size + size_s + 1));
	i = -1;
	while (s[++i])
		(*str)[size + i] = s[i];
	return (size + size_s + 1);
}
