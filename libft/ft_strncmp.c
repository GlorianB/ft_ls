/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 04:52:03 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/07 05:18:03 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t index;

	index = 0;
	if (n == 0)
		return ((unsigned char)0);
	while (s1[index] && s2[index] && index < n - 1 && s1[index] == s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
