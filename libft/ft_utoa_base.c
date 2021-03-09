/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:55:16 by santa             #+#    #+#             */
/*   Updated: 2019/09/20 06:49:29 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_utoa_base(unsigned nb, int base)
{
	char		*res;
	unsigned	tmp;

	if (!(res = ft_strnew(0)))
		return (NULL);
	if (nb == 0)
		return (res = ft_straddc(res, '0'));
	while (nb)
	{
		tmp = nb % base;
		res = ft_straddc(res, ft_convert_base(tmp));
		nb = nb / base;
	}
	ft_strrev(res);
	return (res);
}

char	*ft_ulltoa_base(unsigned long long nb, int base)
{
	char				*res;
	unsigned long long	tmp;

	if (!(res = ft_strnew(0)))
		return (NULL);
	if (nb == 0)
		return (res = ft_straddc(res, '0'));
	while (nb)
	{
		tmp = nb % base;
		res = ft_straddc(res, ft_convert_base(tmp));
		nb = nb / base;
	}
	ft_strrev(res);
	return (res);
}

char	*ft_ultoa_base(unsigned long n, int base)
{
	return (ft_ulltoa_base(n, base));
}

char	*ft_ulltoa(unsigned long long n)
{
	return (ft_ulltoa_base(n, 10));
}

char	*ft_ultoa(unsigned long n)
{
	return (ft_ulltoa_base(n, 10));
}
