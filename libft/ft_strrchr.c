/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 23:04:29 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/10 23:17:22 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t	index;
	size_t	len;
	int		tmp;

	index = 0;
	tmp = -1;
	len = ft_strlen(s);
	while (index <= len)
	{
		if (s[index] == (char)c)
			tmp = index;
		index++;
	}
	if (tmp == -1)
		return (NULL);
	return ((char *)(s + tmp));
}
