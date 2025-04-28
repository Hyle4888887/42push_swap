/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:52:14 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/22 16:39:01 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isascii(int c)
{
	return (c <= 127 && c >= 0);
}

bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}

bool	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}
