/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_manipulate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:09:40 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/23 11:05:16 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
	return ;
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (s == NULL)
		return (NULL);
	res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	ft_malloc(char **tab, char const *s, int start, size_t len)
{
	if (start >= ft_strlen(s))
	{
		(*tab) = (char *)malloc(1 * sizeof(char));
		if (!*tab)
			return (0);
		(*tab)[0] = '\0';
		return (2);
	}
	if ((start + len) > (unsigned long)ft_strlen(s))
		(*tab) = (char *)malloc(((ft_strlen(s) - start) + 1) * sizeof(char));
	else
		(*tab) = (char *)malloc((len + 1) * sizeof(char));
	if (!*tab)
		return (0);
	return (1);
}

char	*ft_substr(char const *s, int start, size_t len)
{
	size_t	i;
	char	*res;
	int		a;

	if (!s)
		return (NULL);
	res = NULL;
	a = ft_malloc(&res, s, start, len);
	if (a == 0)
		return (NULL);
	else if (a == 2)
		return (res);
	i = 0;
	while ((i < len) && (s[start + i] != '\0'))
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
