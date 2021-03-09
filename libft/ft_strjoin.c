/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 07:05:48 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/11 05:28:00 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	int		index;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((res = ft_strnew(len)) == NULL)
		return (NULL);
	index = -1;
	while (s1[++index])
		res[index] = s1[index];
	index = 0;
	len = ft_strlen(s1);
	while (s2[index])
	{
		res[index + len] = s2[index];
		index++;
	}
	res[index + len] = '\0';
	return (res);
}
