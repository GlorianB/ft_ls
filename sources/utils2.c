/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:36:57 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/07 11:52:35 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			create_flag_mask(char *opt)
{
	int i;
	int res;

	res = 0;
	i = 0;
	if (opt[i] != '-')
		return (0);
	while (opt[++i])
	{
		if (attribute_value()[(int)opt[i]])
			res |= attribute_value()[(int)opt[i]];
		else
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(opt[i]);
			ft_putstr("\nUsage: ls [-AGRahlprt] [file...]\n");
			exit(1);
		}
	}
	return (res);
}

void		print_tab(char **tab)
{
	int j;

	j = 0;
	while (tab[j] && *tab[j])
	{
		ft_putstr(tab[j]);
		ft_putchar('\n');
		j++;
	}
}

int			test_slash(char *str)
{
	if (str[ft_strlen(str) - 1] == '/')
		return (1);
	return (0);
}

void		stat_or_lstat(t_dir *dir, int i)
{
	if (S_ISLNK(dir->dstat.st_mode) && test_slash(dir->parse.args[i]))
	{
		if (stat(dir->parse.args[i], &(dir->dstat)) < 0)
			ft_print_error(dir->parse.args[i]);
	}
	else if (lstat(dir->parse.args[i], &(dir->dstat)) < 0)
		ft_print_error(dir->parse.args[i]);
}
