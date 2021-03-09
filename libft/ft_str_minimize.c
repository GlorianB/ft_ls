/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_minimize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:51:12 by santa             #+#    #+#             */
/*   Updated: 2019/09/14 04:50:48 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_minimize(char **str)
{
	int	index;

	index = 0;
	while ((*str)[index])
	{
		(*str)[index] = ft_tolower((*str)[index]);
		index++;
	}
}
