/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:51:38 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/25 16:08:39 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	unsigned char	*res;
	unsigned char	*str;
	int				i;

	i = -1;
	res = (unsigned char *)malloc((new_size + 1) * sizeof(unsigned char));
	str = (unsigned char *)ptr;
	while (str[++i] && (size_t)i <= new_size)
		res[i] = str[i];
	while ((size_t)i <= new_size)
		res[i++] = 0;
	free(ptr);
	return ((void *)res);
}
