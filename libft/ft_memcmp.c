/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 08:50:34 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/09 08:59:12 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
		{
			return (((unsigned char *)s1)[index] -
					((unsigned char *)s2)[index]);
		}
		index++;
	}
	return (0);
}
