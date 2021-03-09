/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 01:38:56 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/11/01 01:38:58 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;

	len = ft_strlen(dst);
	if (len >= size)
		return (size + ft_strlen(src));
	ft_strncat(dst, src, size - len - 1);
	return (len + ft_strlen(src));
}
