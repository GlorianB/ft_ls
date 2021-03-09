/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 23:22:57 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/11 00:38:30 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	size_t index;

	if (!(*needle))
		return ((char *)haystack);
	index = 0;
	while (haystack[index])
	{
		while (haystack[index] == needle[index] || !(needle[index]))
		{
			if (!(needle[index]))
				return ((char *)(haystack));
			index++;
		}
		index = 0;
		haystack++;
	}
	return (NULL);
}
