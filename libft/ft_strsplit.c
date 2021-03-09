/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:41:53 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/05/06 01:19:01 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	index;
	size_t	len;
	char	**res;

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char*) * (ft_count_str_sep(s, c) + 1))))
		return (NULL);
	index = 0;
	len = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			s++;
		if (s[index] && s[index] != c)
		{
			while (s[index] && s[index] != c)
				index++;
			res[len++] = ft_strsub(s, 0, index);
			s = s + index;
			index = 0;
		}
	}
	res[len] = 0;
	return (res);
}
