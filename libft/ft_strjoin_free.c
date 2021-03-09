/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 07:05:48 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/09/22 20:18:02 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_str(char const *s1, char const *s2, int opt)
{
	if (opt == 1 || opt == 3)
		free((void *)s1);
	if (opt == 2 || opt == 3)
		free((void *)s2);
}

char		*ft_strjoin_free(char const *s1, char const *s2, int opt)
{
	char	*res;
	size_t	len;
	int		index;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((res = ft_strnew(len)) == NULL)
		return (NULL);
	index = -1;
	while (s1[++index])
		res[index] = s1[index];
	index = 0;
	len = ft_strlen(s1);
	while (s2[index])
	{
		res[index + len] = s2[index];
		index++;
	}
	res[index + len] = '\0';
	opt ? free_str(s1, s2, opt) : 0;
	return (res);
}
