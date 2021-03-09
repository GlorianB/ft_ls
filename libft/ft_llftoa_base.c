/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llftoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:22:51 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/09/23 23:15:12 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_roundc2(char **nb, int i)
{
	(*nb)[i] = '0';
	while (i > 0 && (*nb)[i - 1] == '9')
	{
		i--;
		(*nb)[i] = '0';
	}
	(*nb)[i - 1] += 1;
}

char		*ft_roundc(char *floattant, int accur)
{
	int		i;
	char	*dst;
	char	*nb;

	if (!(nb = ft_strnew(accur + ft_strlen(floattant)))
	|| !(dst = ft_strnew(accur + ft_strlen(floattant))))
		return (0);
	i = -1;
	while (floattant[++i])
		nb[i] = floattant[i];
	i = 0;
	while (nb[i] != '.')
		i++;
	accur += (accur ? i + 1 : i);
	i = accur;
	if (nb[i] && nb[i] >= '5')
		ft_roundc2(&nb, i);
	dst[accur] = '\0';
	while (accur--)
		dst[accur] = (nb[accur] ? nb[accur] : '0');
	free(nb);
	free(floattant);
	return (dst);
}

char		*ft_llftoa_base(long double nb, int base, int accur)
{
	char		*res;
	int			negative;
	long long	tmp;
	long double	fpart;

	accur++;
	negative = (nb < 0. ? 1 : 0);
	nb < 0 ? nb *= -1 : 0;
	fpart = nb - (long)nb;
	if (!(res = ft_strnew(0)))
		return (0);
	if (nb == 0.)
		return (res = ft_straddc(res, '0'));
	while ((long)nb > 0)
	{
		tmp = (nb < 0) ? (((long)nb % base) * -1) : ((long)nb % base);
		res = ft_straddc(res, ft_convert_base(tmp));
		nb = (long)nb / base;
	}
	negative ? res = ft_straddc(res, '-') : 0;
	ft_strrev(res);
	tmp = fpart * ft_power(base, accur);
	res = ft_strjoin_free(ft_straddc(res, '.'), ft_ulltoa_base(tmp, base), 3);
	res = ft_straddc(res, '\0');
	return (ft_roundc(res, accur - 1));
}

char		*ft_lftoa(double nb, int accur)
{
	return (ft_llftoa_base(nb, 10, accur));
}

char		*ft_ftoa(float nb, int accur)
{
	return (ft_llftoa_base(nb, 10, accur));
}
