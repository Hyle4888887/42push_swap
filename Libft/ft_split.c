/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:30:23 by mpoirier          #+#    #+#             */
/*   Updated: 2025/02/24 17:51:26 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_countw(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static char	**ft_free(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static void	ft_second(char **tab, size_t *len, char c)
{
	size_t	j;

	*tab += *len;
	*len = 0;
	while (**tab && **tab == c)
		(*tab)++;
	j = 0;
	while ((*tab)[j])
	{
		if ((*tab)[j] == c)
			return ;
		(*len)++;
		j++;
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*w;
	size_t	count;
	size_t	len;

	if (s == NULL)
		return (NULL);
	res = (char **)malloc((ft_countw(s, c) + 1) * sizeof(char *));
	if (!res)
		return (ft_free(res, ft_countw(s, c) + 1));
	w = (char *)s;
	count = 0;
	len = 0;
	while (count < ft_countw(s, c))
	{
		ft_second(&w, &len, c);
		res[count] = (char *)malloc((len + 1) * sizeof(char));
		if (!res[count])
			return (ft_free(res, ft_countw(s, c) + 1));
		ft_strlcpy(res[count], w, len + 1);
		count++;
	}
	res[count] = NULL;
	return (res);
}

