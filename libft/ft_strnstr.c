/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 00:42:25 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/11 02:38:19 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t index;
	size_t j;

	if (!(*needle))
		return ((char *)haystack);
	index = 0;
	while (haystack[index] && index <= len)
	{
		j = 0;
		while ((haystack[j + index] == needle[j]
				&& j + index < len) || !(needle[j]))
		{
			if (!(needle[j]))
				return ((char *)(haystack + index));
			j++;
		}
		index++;
	}
	return (NULL);
}
