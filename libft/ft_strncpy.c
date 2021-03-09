/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 06:04:12 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/11 12:58:39 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	size_t index;

	index = 0;
	while (index < len)
	{
		if (index < ft_strlen(src))
			dst[index] = src[index];
		else
			dst[index] = '\0';
		index++;
	}
	return (dst);
}
