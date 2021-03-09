/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:44:06 by santa             #+#    #+#             */
/*   Updated: 2019/09/23 23:45:20 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddc(char *str, char c)
{
	int		index;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	index = 0;
	while (str[index])
	{
		res[index] = str[index];
		index++;
	}
	free(str);
	res[index] = c;
	index++;
	res[index] = '\0';
	return (res);
}
