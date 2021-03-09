/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_join_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:10:28 by lachille          #+#    #+#             */
/*   Updated: 2020/03/07 12:39:11 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	fill_line2(t_line *line, int i)
{
	ft_strcpy_at(line->line, line->mode[i], &line->pos, 0);
	ft_strcpy_at(line->line, add_space(line->len_link,
		line->link[i]), &line->pos, 1);
	ft_strcpy_at(line->line, line->link[i], &line->pos, 0);
	ft_strcpy_at(line->line, add_space(line->len_user,
		line->user[i]), &line->pos, 1);
	ft_strcpy_at(line->line, line->user[i], &line->pos, 0);
	ft_strcpy_at(line->line, "  ", &line->pos, 0);
	ft_strcpy_at(line->line, line->grp[i], &line->pos, 0);
	ft_strcpy_at(line->line, add_space(line->len_grp,
		line->grp[i]), &line->pos, 1);
	ft_strcpy_at(line->line, add_space(line->len_size,
		line->size[i]), &line->pos, 1);
	ft_strcpy_at(line->line, line->size[i], &line->pos, 0);
	ft_strcpy_at(line->line, " ", &line->pos, 0);
	ft_strcpy_at(line->line, line->date[i], &line->pos, 0);
	ft_strcpy_at(line->line, " ", &line->pos, 0);
	free(line->mode[i]);
	free(line->link[i]);
	free(line->user[i]);
	free(line->grp[i]);
	free(line->size[i]);
	free(line->date[i]);
}

void		fill_line(int i, t_line *line)
{
	char	*tmp;

	if (line->pos + 512 >= line->alloc)
	{
		line->alloc *= 2;
		if (!(tmp = ft_strdup(line->line)))
			exit(1);
		free(line->line);
		if (!(line->line = ft_strnew(line->alloc)))
			exit(1);
		line->pos = 0;
		ft_strcpy_at(line->line, tmp, &line->pos, 1);
	}
	fill_line2(line, i);
}

static void	free_s_line(t_line *line)
{
	ft_strdel(&(line->line));
	free(line->mode);
	free(line->link);
	free(line->user);
	free(line->grp);
	free(line->size);
	free(line->date);
}

static void	print_line2(t_dir *dir, t_line *line, int i)
{
	if (!(line->line = ft_strnew(line->alloc)))
		exit(1);
	ft_strcpy_at(line->line, "total ", &line->pos, 0);
	ft_strcpy_at(line->line, ft_itoa(line->total), &line->pos, 1);
	ft_strcpy_at(line->line, "\n", &line->pos, 0);
	while (++i <= dir->index)
	{
		if (!lstat(dir->trash = ft_strjoin_free(dir->path,
			dir->files[i], 0), &(dir)->dstat))
		{
			fill_line(i, line);
			if (dir->flag & OPT_G)
				ft_strcpy_at(line->line, opt_g(dir->dstat), &line->pos, 1);
			ft_strcpy_at(line->line, dir->files[i], &line->pos, 0);
			if ((dir->flag & OPT_P) && S_ISDIR(dir->dstat.st_mode))
				ft_strcpy_at(line->line, "/", &line->pos, 0);
			ft_strcpy_at(line->line, "\e[0m", &line->pos, 0);
			print_symlink(*dir, line, i, 1);
			ft_strdel(&(dir->trash));
			ft_strcpy_at(line->line, "\n", &line->pos, 0);
		}
		ft_strdel(&(dir->trash));
	}
	ft_putstr(line->line);
	free_s_line(line);
}

void		print_line_without_joinfree(t_dir dir)
{
	int		i;
	t_line	line;

	i = -1;
	line.pos = 0;
	line.alloc = 1024;
	if (dir.index >= 0)
	{
		if (!(alloc_tab_line_and_init_len(&line, dir.index)))
			exit(1);
		while (++i <= dir.index)
		{
			if (!(lstat(dir.trash = ft_strjoin_free(dir.path,
				dir.files[i], 0), &(dir.dstat))))
			{
				line.total += dir.dstat.st_blocks;
				fill_tabs(dir, &line, i);
			}
			else
				ft_print_error(dir.trash);
			ft_strdel(&(dir.trash));
		}
		print_line2(&dir, &line, -1);
	}
}
