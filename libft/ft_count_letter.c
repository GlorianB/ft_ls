/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:46:52 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/11 07:18:59 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_letter(char const *s)
{
	size_t index;
	size_t res;

	index = 0;
	res = 0;
	while (s[index])
	{
		if (ft_isalnum(s[index]))
			res++;
		index++;
	}
	return (res);
}
