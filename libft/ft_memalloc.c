/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 03:48:23 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/06 05:13:18 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t		index;
	char		*res;

	if ((res = (char *)malloc(size)) == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		res[index] = '\0';
		index++;
	}
	return ((void*)res);
}
