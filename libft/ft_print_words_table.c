/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:44:49 by gbikoumo          #+#    #+#             */
/*   Updated: 2019/04/14 15:04:39 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_table(char **tab)
{
	size_t	index;

	index = 0;
	while (tab[index])
	{
		ft_putendl(tab[index]);
		index++;
	}
}
