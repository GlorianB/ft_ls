/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_classic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:02:14 by lachille          #+#    #+#             */
/*   Updated: 2020/03/07 11:51:32 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	print_classic_solo_file2(t_classic *classic, t_dir *dir)
{
	classic->i = -1;
	classic->len = 1;
	classic->mul = 0;
	classic->pos = 0;
	if (!(dir->parse.file = malloc(sizeof(char *) * dir->parse.nb_args + 1)))
		exit(1);
	while (++classic->i < dir->parse.nb_args)
	{
		classic->nb_line = ft_strlen(dir->parse.args[classic->i]);
		if (classic->nb_line + 1 > classic->len)
			classic->len = classic->nb_line + 1;
		if (!dir->parse.type[classic->i])
			dir->parse.file[classic->mul++] = ft_strdup(
				dir->parse.args[classic->i]);
	}
}

static void	print_classic_solo_file3(t_classic *classic, t_dir *dir)
{
	classic->i ? ft_strcpy_at(classic->line, "\n", &classic->pos, 0) : 0;
	classic->mul = 0;
	while ((classic->nb_line * classic->mul)
		+ classic->i < dir->parse.nb_args)
	{
		if (lstat(dir->parse.file[(classic->nb_line * classic->mul)
			+ classic->i], &(dir)->dstat) < 0)
			ft_print_error(dir->parse.file[(classic->nb_line * classic->mul)
			+ classic->i]);
		dir->flag & OPT_G ? ft_strcpy_at(classic->line, opt_g(dir->dstat),
			&classic->pos, 1) : 0;
		ft_strcpy_at(classic->line, dir->parse.file[(classic->nb_line
			* classic->mul) + classic->i], &classic->pos, 0);
		if (dir->flag & OPT_G)
			ft_strcpy_at(classic->line, "\e[0m", &classic->pos, 0);
		if ((dir->flag & OPT_P) && S_ISDIR(dir->dstat.st_mode))
			ft_strcpy_at(classic->line, "/", &classic->pos, 0);
		ft_strcpy_at(classic->line, add_space(classic->len - 1,
			dir->parse.file
			[(classic->nb_line * classic->mul) + classic->i]),
				&classic->pos, 1);
		free(dir->parse.file[(classic->nb_line * classic->mul)
			+ classic->i]);
		classic->mul++;
	}
}

void		print_classic_solo_file(t_dir dir)
{
	t_classic	classic;

	if (dir.parse.nb_args > 0)
	{
		print_classic_solo_file2(&classic, &dir);
		dir.parse.nb_args = classic.mul;
		classic.nb_line = dir.parse.nb_args / (dir.w.ws_col / classic.len) + 1;
		if (dir.parse.nb_args == (dir.w.ws_col / classic.len))
			classic.nb_line--;
		classic.i = -1;
		if (!(classic.line = ft_strnew((classic.len + 16)
			* (dir.parse.nb_args))))
			exit(1);
		while (++classic.i < classic.nb_line)
			print_classic_solo_file3(&classic, &dir);
		free(dir.parse.file);
		if (dir.parse.nb_args)
			ft_strcpy_at(classic.line, "\n", &classic.pos, 0);
		ft_putstr(classic.line);
		ft_strdel(&(classic.line));
	}
}

static void	print_classic2(t_dir *dir, t_classic *classic)
{
	classic->mul = 0;
	while ((classic->nb_line * classic->mul) + classic->i <= dir->index)
	{
		if (lstat(dir->trash = ft_strjoin_free(dir->path, dir->files
			[(classic->nb_line * classic->mul) + classic->i], 0),
				&(dir)->dstat) < 0)
			ft_print_error(dir->trash);
		ft_strdel(&(dir->trash));
		if (dir->flag & OPT_G)
			ft_strcpy_at(classic->line, opt_g(dir->dstat),
				&classic->pos, 1);
		ft_strcpy_at(classic->line, dir->files[(classic->nb_line
			* classic->mul)
			+ classic->i], &classic->pos, 0);
		if (dir->flag & OPT_G)
			ft_strcpy_at(classic->line, "\e[0m", &classic->pos, 0);
		if ((dir->flag & OPT_P) && S_ISDIR(dir->dstat.st_mode))
			ft_strcpy_at(classic->line, "/", &classic->pos, 0);
		ft_strcpy_at(classic->line, add_space(classic->len, dir->files
			[(classic->nb_line * classic->mul) + classic->i]),
				&classic->pos, 1);
		classic->mul++;
	}
	classic->line[0] ? ft_strcpy_at(classic->line, "\n",
		&classic->pos, 0) : 0;
}

void		print_classic(t_dir dir)
{
	t_classic	classic;

	classic.i = -1;
	classic.len = 0;
	classic.nb_line = 1;
	classic.pos = 0;
	if (dir.index >= 0)
	{
		while (++classic.i <= dir.index)
			classic.len < (int)ft_strlen(dir.files[classic.i])
				? classic.len = ft_strlen(dir.files[classic.i]) : 0;
		if (dir.w.ws_col / (classic.len + 1))
			classic.nb_line = dir.index / (dir.w.ws_col
				/ (classic.len + 1)) + 1;
		else
			classic.nb_line = 1;
		classic.i = -1;
		if (!(classic.line = ft_strnew((classic.len + 14) * (dir.index + 1))))
			exit(1);
		while (++classic.i < classic.nb_line)
			print_classic2(&dir, &classic);
		ft_putstr(classic.line);
		ft_strdel(&(classic.line));
	}
}
