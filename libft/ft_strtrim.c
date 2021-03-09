/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:37:27 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/11 08:33:50 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*res;
	size_t			index;
	size_t			len;
	unsigned int	start;

	if (!s)
		return (NULL);
	index = 0;
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		index++;
	if (s[index] == '\0')
		return (ft_strdup(""));
	start = index;
	index = ft_strlen(s) - 1;
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		index--;
	len = index - start + 1;
	if ((res = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	res = ft_strsub(s, start, len);
	return (res);
}
