/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 06:25:14 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/11 05:17:39 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char const *s2)
{
	int		index;
	size_t	lens1;

	index = 0;
	lens1 = ft_strlen(s1);
	while (s2[index])
	{
		s1[index + lens1] = s2[index];
		index++;
	}
	s1[index + lens1] = '\0';
	return (s1);
}
