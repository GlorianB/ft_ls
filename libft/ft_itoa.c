/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 01:57:05 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/14 10:50:15 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*res;
	int			neg;
	long long	nb;

	nb = n;
	neg = 0;
	if (!(res = (char *)malloc(sizeof(char) * (ft_size_nb(n) + 1))))
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		res[neg] = '-';
		neg = 1;
	}
	n = ft_count(n);
	while (n != 0)
	{
		res[neg] = nb / (long long)n + 48;
		nb = nb % (long long)n;
		n = n / 10;
		neg++;
	}
	res[neg] = '\0';
	return (res);
}
