/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:34:04 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/22 16:43:21 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool	ft_isupperalpha(int c)
{
	return (c >= 'A' && c <= 'Z');
}

bool	ft_isloweralpha(int c)
{
	return (c >= 'a' && c <= 'z');
}

bool	ft_str_is(const char *str, bool (*f)(int))
{
	int	i;

	if (!str)
		return (false);
	i = -1;
	while (str[++i])
	{
		if (!(*f)(str[i]))
			return (false);
	}
	return (true);
}
