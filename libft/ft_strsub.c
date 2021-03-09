/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 05:30:00 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/30 19:38:54 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*res;

	if (!s)
		return (NULL);
	if ((res = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		res[index] = s[index + start];
		index++;
	}
	res[index] = '\0';
	return (res);
}
