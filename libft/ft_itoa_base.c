/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:51:56 by santa             #+#    #+#             */
/*   Updated: 2019/09/23 23:53:14 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(int nb, int base)
{
	char	*res;
	int		negative;
	int		tmp;

	if (nb == 0)
		return (ft_straddc(ft_strnew(0), '0'));
	if (!(res = (char*)ft_strnew(0)))
		return (NULL);
	negative = 0;
	if (nb < 0 && base == 10)
		negative = 1;
	while (nb)
	{
		tmp = (negative) ? ((nb % base) * -1) : (nb % base);
		res = ft_straddc(res, ft_convert_base(tmp));
		nb = nb / base;
	}
	if (negative)
		res = ft_straddc(res, '-');
	ft_strrev(res);
	return (res);
}

char	*ft_illtoa_base(long long nb, int base)
{
	char		*res;
	int			negative;
	long long	tmp;

	if (!(res = (char*)ft_strnew(0)))
		return (NULL);
	if (nb == 0)
		return (res = ft_straddc(res, '0'));
	negative = 0;
	if (nb < 0)
		negative = 1;
	while (nb)
	{
		tmp = (negative) ? ((nb % base) * -1) : nb % base;
		res = ft_straddc(res, ft_convert_base(tmp));
		nb = nb / base;
	}
	if (negative)
		res = ft_straddc(res, '-');
	ft_strrev(res);
	return (res);
}

char	*ft_iltoa_base(long n, int base)
{
	return (ft_illtoa_base(n, base));
}

char	*ft_illtoa(long long n)
{
	return (ft_illtoa_base(n, 10));
}

char	*ft_iltoa(long n)
{
	return (ft_illtoa_base(n, 10));
}
