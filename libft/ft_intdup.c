/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 09:33:51 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/03 11:55:36 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intdup(int *tab, int n)
{
	int index;
	int *res;

	if (!(res = (int*)malloc(sizeof(int) * n)))
		exit(1);
	index = -1;
	while (++index < n)
		res[index] = tab[index];
	return (res);
}
