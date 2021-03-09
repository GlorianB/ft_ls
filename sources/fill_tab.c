/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 04:48:25 by lachille          #+#    #+#             */
/*   Updated: 2020/03/07 10:34:48 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		fill_tab_size(t_dir dir, t_line *line, int i)
{
	int		len2;
	char	*tmp;

	len2 = 0;
	if (S_ISBLK(dir.dstat.st_mode) || S_ISCHR(dir.dstat.st_mode))
	{
		line->size[i] = ft_itoa(major(dir.dstat.st_rdev));
		line->size[i] = ft_strjoin_free(line->size[i], ",", 1);
		line->size[i] = ft_strjoin_free(line->size[i],
			add_space(3, tmp = ft_itoa(minor(dir.dstat.st_rdev))), 3);
		line->size[i] = ft_strjoin_free(line->size[i],
			ft_itoa(minor(dir.dstat.st_rdev)), 3);
		ft_strdel(&tmp);
	}
	else
	{
		if (!(line->size[i] = ft_ulltoa(dir.dstat.st_size)))
			exit(1);
		dir.flag & OPT_H ? line->size[i] = opt_h(line->size[i]) : 0;
	}
	len2 = ft_strlen(line->size[i]);
	if (line->len_size < len2)
		line->len_size = len2;
}

static void	fill_tab_date2(t_fill *vars, t_line *line, int i)
{
	while (vars->tmp[vars->j])
	{
		if (vars->tmp[vars->j] == ':')
			vars->count_ddot++;
		if (line->date_mode == 1 && vars->count_space == 4)
		{
			line->date[i][vars->k++] = ' ';
			line->date_mode++;
		}
		if (vars->count_space == 1 || vars->count_space == 2 ||
				(!line->date_mode && vars->count_space == 3
				&& vars->count_ddot < 2)
				|| (line->date_mode && vars->count_space == 4
				&& vars->tmp[vars->j] != '\n'))
			line->date[i][vars->k++] = vars->tmp[vars->j];
		if (vars->j > 0 && vars->tmp[vars->j - 1] != ' '
			&& vars->tmp[vars->j] == ' ')
			vars->count_space++;
		vars->j++;
	}
}

void		fill_tab_date(t_dir dir, t_line *line, int i)
{
	t_fill vars;

	vars.j = 0;
	vars.k = 0;
	vars.len2 = 0;
	vars.count_ddot = 0;
	vars.count_space = 0;
	if (!(line->date[i] = ft_strnew(14)))
		exit(1);
	line->date_mode = (time(0) - dir.dstat.st_mtime > 2635200
	|| time(0) - dir.dstat.st_mtime < -2635200 ? 1 : 0);
	vars.tmp = ctime(&(dir.dstat.st_mtime));
	fill_tab_date2(&vars, line, i);
	vars.len2 = ft_strlen(line->date[i]);
	if (line->len_date < vars.len2)
		line->len_date = vars.len2;
}

void		fill_dir_files(t_dir *dir)
{
	unsigned size_buf;

	size_buf = 8;
	dir->index = -1;
	if (!(dir->files = (char**)malloc(sizeof(char *) * size_buf)))
		exit(1);
	while ((dir->pdirent = readdir(dir->directory)))
	{
		if (!(dir->files[++dir->index] = ft_strdup(dir->pdirent->d_name)))
			exit(1);
		if ((unsigned)dir->index + 1 >= size_buf)
			dir->files = realloc_line(dir->files, &size_buf);
	}
}
