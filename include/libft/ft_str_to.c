/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:42:49 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/23 11:08:20 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}

char	*ft_str_to(const char *str, int (*f)(int))
{
	int		i;
	char	*res;

	i = -1;
	res = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[++i])
	{
		if ((*f)(str[i]) != str[i])
			res[i] = (*f)(str[i]);
		else
			res[i] = str[i];
	}
	res[i] = '\0';
	return (res);
}

char	*ft_str_inversealpha(const char *str)
{
	int		i;
	char	*res;

	i = -1;
	res = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[++i])
	{
		if (ft_tolower(str[i]) != str[i])
			res[i] = ft_tolower(str[i]);
		else if (ft_toupper(str[i]) != str[i])
			res[i] = ft_toupper(str[i]);
		else
			res[i] = str[i];
	}
	res[i] = '\0';
	return ((char *)res);
}
