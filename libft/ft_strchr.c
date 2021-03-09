/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:50:12 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/10 22:55:27 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	size_t index;
	size_t len;

	index = 0;
	len = ft_strlen(s);
	while (index <= len)
	{
		if (s[index] == (char)c)
			return ((char *)(s + index));
		index++;
	}
	return (NULL);
}
