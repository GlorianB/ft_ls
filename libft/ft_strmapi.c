/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 04:13:10 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/07 04:17:09 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*res;

	if (s && f)
	{
		if ((res = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		index = 0;
		while (index < ft_strlen(s))
		{
			res[index] = f(index, s[index]);
			index++;
		}
		return (res);
	}
	else
	{
		res = NULL;
		return (res);
	}
}
