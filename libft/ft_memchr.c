/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 08:42:24 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/09 08:57:39 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char)c)
			return ((unsigned char *)s + index);
		index++;
	}
	return (NULL);
}
