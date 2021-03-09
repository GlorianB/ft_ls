/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 07:26:31 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/11 08:49:29 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_str(char const *s)
{
	int index;
	int res;

	index = 0;
	res = 0;
	if (!s)
		return (res);
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		index++;
	while (s[index])
	{
		while (s[index] && (s[index] == ' ' || s[index] == '\n' ||
				s[index] == '\t'))
			index++;
		if (s[index] && (s[index] != ' ' || s[index] != '\n' ||
				s[index] != '\t'))
			res++;
		while (s[index] && (s[index] != ' ' || s[index] != '\n' ||
				s[index] != '\t'))
			index++;
	}
	return (res);
}
