/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 06:35:31 by lachille          #+#    #+#             */
/*   Updated: 2020/03/07 12:36:47 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		reset_parse_type(t_dir *dir)
{
	int i;

	i = -1;
	while (++i < dir->parse.nb_args)
	{
		if (lstat(dir->parse.args[i], &(dir->dstat)) < 0)
			ft_print_error(dir->parse.args[i]);
		if (S_ISREG(dir->dstat.st_mode))
			dir->parse.type[i] = 0;
		else
			dir->parse.type[i] = 1;
	}
}

static void		handle_args(t_dir *dir, int ac, char **av)
{
	dir->test_files = 0;
	dir->index = -1;
	dir->test_if_dir = false;
	if (ioctl(0, TIOCGWINSZ, &(dir->w)) < 0)
		perror("ioctl fail\n");
	!dir->w.ws_col ? dir->w.ws_col = 20 : 0;
	dir->parse.type = NULL;
	parse_args(dir, av, ac);
	dir->mode = 1;
	dir->flag & OPT_T ? opt_t(dir->parse.args, 0, dir->parse.nb_args - 1, dir)
		: 0;
	dir->flag & OPT_RMIN
		? dir->parse.args = opt_r(dir->parse.args, dir->parse.nb_args, dir) : 0;
	dir->flag & OPT_T || dir->flag & OPT_RMIN ? reset_parse_type(dir) : 0;
	dir->parse.i = -1;
	while (++dir->parse.i < dir->parse.nb_args)
		!dir->parse.type[dir->parse.i] ? dir->test_files = 1 : 0;
	if (dir->parse.nb_args)
		dir->flag & OPT_L ? print_solo_file_line(*dir)
			: print_classic_solo_file(*dir);
	dir->parse.i = -1;
}

static int		handle_error(t_dir dir, int ac)
{
	dir.parse.i ? ft_putstr("\n") : 0;
	if (ac > 2)
		ft_print_without_slash(dir.path);
	ft_print_error(dir.parse.args[dir.parse.i]);
	ft_strdel(&(dir.path));
	free_args(&dir);
	return (0);
}

void			init_main(t_dir *dir, int ac, char **av)
{
	dir->index = 0;
	dir->flag = 0;
	dir->parse.i = -1;
	handle_args(dir, ac, av);
	dir->mode = 0;
}

int				main(int ac, char **av)
{
	t_dir dir;

	init_main(&dir, ac, av);
	while (++dir.parse.i < dir.parse.nb_args)
	{
		dir.path = ft_strnew(0);
		if (dir.parse.type[dir.parse.i])
		{
			if (dir.parse.args[dir.parse.i]
				[ft_strlen(dir.parse.args[dir.parse.i]) - 1] != '/')
				dir.path = ft_strjoin_free(dir.path,
					ft_strjoin_free(dir.parse.args[dir.parse.i], "/", 0), 3);
			else
				dir.path = ft_strjoin_free(dir.path,
					dir.parse.args[dir.parse.i], 1);
			if (!(dir.directory = opendir(dir.parse.args[dir.parse.i])))
				return (handle_error(dir, ac));
			ft_ls(dir, dir.path);
		}
		dir.path ? free(dir.path) : 0;
	}
	free(dir.parse.type);
	free_args(&dir);
	return (0);
}
