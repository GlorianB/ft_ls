/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 01:52:55 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/26 02:06:20 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*tmp;

	tmp = ft_strdup((char *)ptr);
	ft_memdel(ptr);
	if (!(ptr = malloc(sizeof(char) * (ft_strlen(tmp) + size + 1))))
		return (NULL);
	ptr = ft_strcpy(ptr, tmp);
	return (ptr);
}
