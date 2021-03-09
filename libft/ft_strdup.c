/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 05:41:37 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/03 11:52:20 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	size_t	len;
	char	*res;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if ((res = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		exit(1);
	res = ft_strcpy(res, s1);
	return (res);
}
