/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:38:06 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/23 16:15:16 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to have the lenght of a string
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// Function to have the lenght of a number (max: long long)
int	ft_nbrlen(long long nb, int bn)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= bn;
		i++;
	}
	return (i);
}

// Function to have the lenght of a unsigned number (max: size_t)
int	ft_nbulen(size_t nb, int bn)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb /= bn;
		i++;
	}
	return (i);
}

// Function to have the lenght of an address (void *ptr)
int	ft_ptrlen(unsigned long addr)
{
	int	i;

	i = 0;
	while (addr > 0)
	{
		addr /= 16;
		i++;
	}
	return (i);
}
