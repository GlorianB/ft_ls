/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 02:04:37 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/07 04:10:30 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			res[index] = f(s[index]);
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
