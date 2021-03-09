/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 04:21:26 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/07 04:34:54 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	return (s1[0] != s2[0] || !s1[0] || !s2[0] ?
			(unsigned char)s1[0] - (unsigned char)s2[0] :
			ft_strcmp(s1 + 1, s2 + 1));
}
