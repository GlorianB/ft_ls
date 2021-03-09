/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santa <santa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:41:58 by santa             #+#    #+#             */
/*   Updated: 2019/09/14 02:56:12 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int		index;
	int		index2;
	char	tmp;

	index = 0;
	index2 = 0;
	while (str[index2])
		index2++;
	index2--;
	while (str[index] && index < index2)
	{
		tmp = str[index];
		str[index] = str[index2];
		str[index2] = tmp;
		index++;
		index2--;
	}
}
