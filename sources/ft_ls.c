/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:08:04 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/07 11:35:58 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_ls_args(t_dir *dir, char *path)
{
	dir->path = ft_strdup(path);
	fill_dir_files(dir);
	dir->directory ? closedir(dir->directory) : 0;
	if (dir->parse.nb_args > 1 || ((dir->flag & OPT_R) && dir->test_if_dir))
	{
		dir->parse.i || ((dir->flag & OPT_R) && dir->test_if_dir)
			|| dir->test_files ? ft_putstr("\n") : 0;
		write(1, path, ft_strlen(path) - 1);
		ft_putstr(":\n");
	}
	opt_a(dir);
	merge_sort(dir->files, 0, dir->index);
	dir->mode = 0;
	dir->flag & OPT_T ? opt_t(dir->files, 0, dir->index, dir) : 0;
	dir->flag & OPT_RMIN ? dir->files = opt_r(dir->files, dir->index + 1, NULL)
		: 0;
	dir->flag & OPT_L ? print_line_without_joinfree(*dir) : print_classic(*dir);
}

void	ft_ls(t_dir dir, char *path)
{
	int i;

	ft_ls_args(&dir, path);
	i = -1;
	while (++i <= dir.index && (dir.flag & OPT_R))
	{
		path = ft_strjoin_free(dir.path, dir.files[i], 0);
		if (lstat(path, &(dir).dstat) < 0)
			ft_print_error(path);
		if (S_ISDIR(dir.dstat.st_mode) && ft_strcmp(".", dir.files[i])
				&& ft_strcmp("..", dir.files[i]))
		{
			dir.test_if_dir = true;
			path = ft_strjoin_free(path, "/", 1);
			if (!(dir.directory = opendir(path)))
			{
				ft_print_error(path);
				dir.directory = NULL;
			}
			else
				ft_ls(dir, path);
		}
		OPT_R & dir.flag ? ft_strdel(&path) : 0;
	}
	free_dir(&dir);
}
