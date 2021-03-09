/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:43:09 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/07 11:30:08 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir	new_t_dir(t_dir old_dir, int *i)
{
	t_dir new_dir;

	new_dir = old_dir;
	new_dir.path = ft_strjoin_free(old_dir.path, old_dir.files[*i], 0);
	new_dir.path = ft_strjoin_free(new_dir.path, "/", 1);
	new_dir.index = -1;
	if (ft_strcmp(".", old_dir.files[*i]) && ft_strcmp("..", old_dir.files[*i]))
		if (!(new_dir.directory = opendir(new_dir.path)))
		{
			ft_print_error(old_dir.files[*i]);
			*i += 1;
			return (new_t_dir(old_dir, i));
		}
	return (new_dir);
}

void	free_args(t_dir *dir)
{
	int index;

	index = -1;
	dir->parse.type = NULL;
	while (++index < dir->parse.nb_args)
		ft_strdel(&(dir->parse.args[index]));
	free(dir->parse.args);
	index = -1;
}

void	free_dir(t_dir *dir)
{
	int index;

	index = -1;
	ft_strdel(&(dir->path));
	while (++index <= dir->index)
		ft_strdel(&(dir->files[index]));
	free(dir->files);
	dir->files = NULL;
	dir->info_uid = NULL;
	dir->pdirent = NULL;
	dir = NULL;
}

void	ft_print_error(char *arg1)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(arg1);
}

void	ft_print_without_slash(char *str)
{
	write(1, str, ft_strlen(str) - 1);
	ft_putstr(":\n");
}
