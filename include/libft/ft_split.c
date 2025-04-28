/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:24:17 by mpoirier          #+#    #+#             */
/*   Updated: 2024/11/18 08:50:45 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

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

/*#include <stdio.h>
int main() {
    char *str = "Hello,world,this,is,ia,test";
    char sep = ',';
    char **result;
    int i = 0;

    // Appel de ft_split pour découper la chaîne
    result = ft_split(str, sep);

    // Si le tableau n'est pas NULL, afficher chaque élément
    if (result) {
        while (result[i]) {
            printf("Part %d: %s\n", i, result[i]);
            i++;
        }

        // Libérer la mémoire allouée pour le tableau de chaînes
        i = 0;
        while (result[i]) {
            free(result[i]);
            i++;
        }
        free(result);
    } else {
        printf("Memory allocation failed or invalid input.\n");
    }

    return 0;
}*/
