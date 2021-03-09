/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:03:03 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/24 06:15:16 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(char const *s1, char c)
{
	size_t	len;
	size_t	index;
	char	*res;

	len = ft_strclen(s1, c);
	if ((res = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		res[index] = s1[index];
		index++;
	}
	res[index] = s1[index];
	return (res);
}
