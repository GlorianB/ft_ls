/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:29:49 by lachille          #+#    #+#             */
/*   Updated: 2020/02/27 10:29:54 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		fill_tabs(t_dir dir, t_line *line, int i)
{
	fill_tab_mode(dir, line, i);
	fill_tab_link(dir, line, i);
	fill_tab_user(dir, line, i);
	fill_tab_grp(dir, line, i);
	fill_tab_size(dir, line, i);
	fill_tab_date(dir, line, i);
}

int			alloc_tab_line_and_init_len(t_line *line, int len)
{
	if (!(line->mode = malloc(sizeof(char *) * (len + 1)))
			|| !(line->link = malloc(sizeof(char *) * (len + 1)))
			|| !(line->user = malloc(sizeof(char *) * (len + 1)))
			|| !(line->grp = malloc(sizeof(char *) * (len + 1)))
			|| !(line->size = malloc(sizeof(char *) * (len + 1)))
			|| !(line->date = malloc(sizeof(char *) * (len + 1))))
		return (0);
	line->len_mode = 0;
	line->len_link = 0;
	line->len_user = 0;
	line->len_grp = 0;
	line->len_size = 0;
	line->len_date = 0;
	line->total = 0;
	line->alloc = 1024;
	return (1);
}

static void	print_solo_file_line2(t_dir *dir, t_line *line, int i)
{
	while (++i < dir->parse.nb_args)
	{
		if (!dir->parse.type[i])
		{
			fill_line(i, line);
			stat_or_lstat(dir, i);
			if (dir->flag & OPT_G)
				ft_strcpy_at(line->line, opt_g(dir->dstat), &line->pos, 1);
			ft_strcpy_at(line->line, dir->parse.args[i], &line->pos, 0);
			if ((dir->flag & OPT_P) && S_ISDIR(dir->dstat.st_mode))
				ft_strcpy_at(line->line, "/", &line->pos, 0);
			ft_strcpy_at(line->line, "\e[0m", &line->pos, 0);
			print_symlink(*dir, line, i, 0);
			ft_strcpy_at(line->line, "\n", &line->pos, 0);
		}
	}
}

void		print_solo_file_line(t_dir dir)
{
	int		i;
	t_line	line;

	line.pos = 0;
	i = -1;
	if (!(alloc_tab_line_and_init_len(&line, dir.parse.nb_args)))
		exit(1);
	while (++i < dir.parse.nb_args)
		if (!dir.parse.type[i])
		{
			stat_or_lstat(&dir, i);
			fill_tabs(dir, &line, i);
		}
	if (!(line.line = ft_strnew(line.alloc)))
		exit(1);
	print_solo_file_line2(&dir, &line, -1);
	ft_putstr(line.line);
	ft_strdel(&(line.line));
	free(line.mode);
	free(line.link);
	free(line.user);
	free(line.grp);
	free(line.size);
	free(line.date);
}
