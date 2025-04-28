/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:54:37 by mpoirier          #+#    #+#             */
/*   Updated: 2025/01/16 17:52:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_second(const char *format, va_list args, char **str)
{
	if (!(*format))
		return (ft_strlen((const char *)(*str)));
	else if (*format == '%')
		return (ft_printc('%', str));
	else if (*format == 'c')
		return (ft_printc(va_arg(args, int), &(*str)));
	else if (*format == 's')
		return (ft_prints(va_arg(args, char *), &(*str)));
	else if (*format == 'i')
		return (ft_printi(va_arg(args, int), &(*str)));
	else if (*format == 'd')
		return (ft_printi(va_arg(args, int), &(*str)));
	else if (*format == 'u')
		return (ft_printu(va_arg(args, unsigned int), &(*str)));
	else if (*format == 'b')
		return (ft_printb(va_arg(args, int), &(*str)));
	else if (*format == 'x')
		return (ft_printx(va_arg(args, long), false, &(*str)));
	else if (*format == 'X')
		return (ft_printx(va_arg(args, long), true, &(*str)));
	else if (*format == 'p')
		return (ft_printp(va_arg(args, void *), &(*str)));
	else
		return (ft_printc((int)(*format), &(*str)));
}

static int	ft_printf3(const char *format, va_list args, char **str, int count)
{
	int	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			count = ft_printf_second(&format[++i], args, str);
		else
			count = ft_printc((int)format[i], &(*str));
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	char	*str;
	va_list	args;

	va_start(args, format);
	count = 1;
	str = (char *)malloc(1 * sizeof(char));
	if (!str)
	{
		free(str);
		return (0);
	}
	str[0] = '\0';
	count = ft_printf3(format, args, &str, count);
	va_end(args);
	ft_putendl_fd((const char *)str, 1);
	free(str);
	return (count);
}
