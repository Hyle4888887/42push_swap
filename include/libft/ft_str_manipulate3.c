/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:24:13 by mpoirier          #+#    #+#             */
/*   Updated: 2024/11/12 16:23:02 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_l2b(const char *b, const char *l, size_t len, size_t ind)
{
	size_t	k;

	k = 0;
	while ((b[ind] == l[k]) && l[k] != '\0' && ind < len)
	{
		ind++;
		k++;
	}
	if (l[k] == '\0')
		return (ind);
	else
		return (ind - k);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = (char *)big;
	if (!*little)
		return (res);
	else if (len <= 0)
		return (NULL);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = ft_l2b(big, little, len, i);
			if (j != i)
				return (&res[i]);
		}
		i++;
	}
	return (NULL);
}

static void	ft_second(char *res, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	l = ft_strlen(s1);
	while (i < l)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	l += ft_strlen(s2);
	while ((i + j) < l)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup((const char *)""));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_second(res, s1, s2);
	return (res);
}

/*#include <stdio.h>
int main()
{
    char *s1 = "Hello, ";
    char *s2 = "world!";

    char *result = ft_strjoin(s1, s2);

    if (result)
    {
        printf("Result: %s\n", result);
        free(result);  // N'oubliez pas de libérer la mémoire allouée
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/
