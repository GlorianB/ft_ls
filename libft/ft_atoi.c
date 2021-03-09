/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 08:25:10 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/16 16:19:17 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int index;
	int signe;
	int res;

	index = 0;
	signe = 1;
	res = 0;
	while (ft_isesc(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			signe = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		res = res * 10 + str[index] - 48;
		index++;
	}
	return (res * signe);
}
