/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 02:39:02 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/02/27 10:30:09 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	*attribute_value(void)
{
	static int	tab[256];

	if (!tab['l'])
	{
		tab['l'] = OPT_L;
		tab['R'] = OPT_R;
		tab['a'] = OPT_AMIN;
		tab['r'] = OPT_RMIN;
		tab['t'] = OPT_T;
		tab['A'] = OPT_A;
		tab['h'] = OPT_H;
		tab['p'] = OPT_P;
		tab['G'] = OPT_G;
	}
	return (tab);
}

int	assign_opt_h(int index)
{
	int letter;

	letter = 'B';
	if (index < 4)
		letter = 'B';
	else if (index < 7)
		letter = 'K';
	else if (index < 10)
		letter = 'M';
	else if (index < 13)
		letter = 'G';
	else if (index < 16)
		letter = 'T';
	else if (index < 19)
		letter = 'P';
	return (letter);
}
