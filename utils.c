/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:07:46 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/14 16:11:58 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1len;

	s1len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (s1len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, s1len + 1);
	return (ptr);
}

void	ft_free(char **ptr)
{
	size_t	i;

	i = 0;
	if (ptr && ptr[i])
		while (ptr[i])
			free(ptr[i++]);
	if (ptr)
	{
		free(ptr);
		ptr = 0;
	}
}
