/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 06:46:53 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/09/27 19:30:00 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcchri(char const *s, int c)
{
	size_t index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (index);
		index++;
	}
	return (-1);
}
