/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 05:58:17 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/24 06:13:30 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(char const *s, char c)
{
	int index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (index + 1);
		index++;
	}
	return (index);
}
