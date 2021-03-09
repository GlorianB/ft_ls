/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:33:45 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/07 12:26:35 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	parse_opt(int ac, char **av, t_dir *dir)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "--"))
			return (i + 1);
		else if (av[i][0] == '-')
			dir->flag |= create_flag_mask(av[i]);
		else
			break ;
	}
	return (i);
}

void		parse_args2(t_dir *dir)
{
	dir->parse.nb_args = 1;
	if (!(dir->parse.args = malloc(sizeof(char *)
		* (dir->parse.nb_args + 1)))
		|| !(dir->parse.type = malloc(sizeof(int) * dir->parse.nb_args)))
		exit(1);
	if (!(dir->parse.args[0] = ft_strdup(".")))
		exit(1);
	dir->parse.type[0] = 1;
	dir->parse.args[1] = NULL;
}

void		parse_args3(t_dir *dir, int index, int ac, char **avcpy)
{
	while (++index < ac)
		if (lstat(avcpy[index], &(dir->dstat)) < 0)
		{
			ft_print_error(avcpy[index]);
			dir->parse.nb_args--;
		}
}

int			parse_args4(t_dir *dir, char **avcpy, int index, int ac)
{
	int j;

	j = 0;
	if (!(dir->parse.args = malloc(sizeof(char *)
		* (dir->parse.nb_args + 1)))
		|| !(dir->parse.type = malloc(sizeof(int) * dir->parse.nb_args)))
		exit(1);
	while (++index < ac)
	{
		if (!(lstat(avcpy[index], &(dir->dstat)) < 0))
		{
			if (!(dir->parse.args[j] = ft_strdup(avcpy[index])))
				exit(1);
			if (S_ISDIR(dir->dstat.st_mode) || (S_ISLNK(dir->dstat.st_mode)
				&& test_slash(dir->parse.args[j]) && dir->flag & OPT_L)
				|| (S_ISLNK(dir->dstat.st_mode) && !(dir->flag & OPT_L)))
				dir->parse.type[j++] = 1;
			else
			{
				dir->parse.type[j++] = 0;
				dir->test_files = 1;
			}
		}
	}
	return (j);
}

void		parse_args(t_dir *dir, char **av, int ac)
{
	int		i;
	int		j;
	int		index;
	char	**avcpy;

	i = parse_opt(ac, av, dir);
	if (i > ac)
		exit(1);
	dir->parse.nb_args = ac - i;
	if (i == ac)
		parse_args2(dir);
	else
	{
		avcpy = ft_tabdup_char(av);
		merge_sort(avcpy, i, ac - 1);
		index = i - 1;
		parse_args3(dir, index, ac, avcpy);
		j = parse_args4(dir, avcpy, index, ac);
		index = -1;
		while (avcpy[++index])
			ft_strdel(&(avcpy[index]));
		free(avcpy);
		dir->parse.args[j] = NULL;
	}
}
