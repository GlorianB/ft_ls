/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 06:32:39 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/11 03:34:07 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t	index;
	size_t	lens1;

	index = 0;
	lens1 = ft_strlen(s1);
	while (index < n && s2[index])
	{
		s1[index + lens1] = s2[index];
		index++;
	}
	s1[index + lens1] = '\0';
	return (s1);
}
