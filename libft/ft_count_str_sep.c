/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_str_sep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 06:07:56 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/14 12:37:21 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_str_sep(char const *s, char separator)
{
	int index;
	int res;

	index = 0;
	res = 0;
	if (!s)
		return (res);
	while (s[index] == separator)
		index++;
	while (s[index])
	{
		while (s[index] && s[index] == separator)
			index++;
		if (s[index] && s[index] != separator)
			res++;
		while (s[index] && s[index] != separator)
			index++;
	}
	return (res);
}
