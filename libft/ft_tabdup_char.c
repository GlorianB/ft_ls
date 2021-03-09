/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 09:30:38 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/03 11:58:29 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup_char(char **tab)
{
	int		index;
	char	**res;

	if (!(res = (char**)malloc(sizeof(char*) * (ft_count_char_elem(tab) + 1))))
		return (NULL);
	index = -1;
	while (tab[++index])
		res[index] = ft_strdup(tab[index]);
	res[index] = NULL;
	return (res);
}
