/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 07:22:13 by lachille          #+#    #+#             */
/*   Updated: 2019/09/20 05:53:57 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_insertc(char **str, char c, int pos)
{
	int		i;
	int		j;
	char	*dst;

	j = 0;
	i = 0;
	if (!str)
		return (0);
	if (!(dst = malloc(sizeof(*dst) * (ft_strlen(*str) + 2))))
		return (0);
	while ((*str)[j])
	{
		if (i == pos)
			dst[i] = c;
		else
		{
			dst[i] = (*str)[j];
			j += 1;
		}
		i++;
	}
	(int)ft_strlen(*str) == pos ? dst[i++] = c : 0;
	dst[i] = '\0';
	free(*str);
	return (dst);
}
