/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:32:40 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/22 12:32:41 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buffer;

	buffer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*buffer == (unsigned char)c)
			return (buffer);
		buffer++;
		i++;
	}
	return (NULL);
}
