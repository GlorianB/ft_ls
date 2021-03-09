/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:30:21 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/22 12:17:22 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s1, size_t len)
{
	size_t	index;
	char	*res;

	index = 0;
	while (index < len && s1[index])
		index++;
	if ((res = (char *)malloc(sizeof(char) * index + 1)) == NULL)
		return (NULL);
	res = ft_strncpy(res, s1, len);
	return (res);
}
