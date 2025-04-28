/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:22:27 by mpoirier          #+#    #+#             */
/*   Updated: 2024/11/18 08:53:41 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((*s) == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

static void	ft_nbrtrim(char const *s1, char const *set, size_t *i, size_t *j)
{
	size_t	a;

	while (s1[(*i)] != '\0')
	{
		a = 0;
		while (set[a] != s1[(*i)] && set[a] != '\0')
			a++;
		if (set[a] == '\0')
			break ;
		else
			(*i)++;
	}
	if ((*i) == (*j))
		return ;
	while ((*j) > 0)
	{
		a = 0;
		while (set[a] != s1[(*j) - 1] && set[a] != '\0')
			a++;
		if (set[a] == '\0')
			break ;
		else
			(*j)--;
	}
}

static void	ft_fillstr(char const *s1, char **res, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while ((start + i) < end)
	{
		(*res)[i] = s1[start + i];
		i++;
	}
	(*res)[i] = '\0';
	return ;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (set == NULL)
	{
		res = (char *)malloc((end + 1) * sizeof(char));
		ft_fillstr(s1, &res, start, end);
		return (res);
	}
	ft_nbrtrim(s1, set, &start, &end);
	res = (char *)malloc(((end - start) + 1) * sizeof(char));
	ft_fillstr(s1, &res, start, end);
	return (res);
}
