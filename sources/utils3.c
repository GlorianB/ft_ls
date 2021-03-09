/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 08:50:01 by lachille          #+#    #+#             */
/*   Updated: 2020/02/27 10:15:59 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_strcpy_at(char *str, char *str2, unsigned int *i, int mode)
{
	int j;

	j = -1;
	while (str2 && str2[++j])
	{
		str[*i + j] = str2[j];
	}
	if (mode)
		free(str2);
	*i += (j == -1 ? j = 0 : j);
}

char	*add_space(int len, char *str)
{
	int		i;
	char	*dst;
	int		minus;

	minus = ft_strlen(str);
	i = -1;
	if (str)
	{
		if (!(dst = ft_strnew((len - minus + 1) >= 0 ? len - minus + 1 : 0)))
			exit(1);
		if (str)
		{
			while (++i <= len - minus)
				dst[i] = ' ';
		}
	}
	else if (!(dst = ft_strnew(0)))
		exit(1);
	return (dst);
}

char	**realloc_line(char **old, unsigned int *buf)
{
	char			**new;
	unsigned int	buf2;
	int				i;

	buf2 = *buf;
	*buf *= 2;
	i = -1;
	if (*buf < buf2 || !(new = malloc(sizeof(char *) * *buf)))
		return (0);
	while (++i < (int)*buf)
	{
		if (i < (int)buf2)
		{
			if (!(new[i] = ft_strdup(old[i])))
				return (0);
			free(old[i]);
		}
	}
	free(old);
	return (new);
}

void	print_symlink(t_dir dir, t_line *line, int i, int mode)
{
	char *buf;

	if (S_ISLNK(dir.dstat.st_mode))
	{
		if (!(buf = ft_strnew(1024)))
			exit(1);
		ft_strcpy_at(line->line, " -> ", &line->pos, 0);
		if (!mode)
		{
			if (readlink(dir.parse.args[i], buf, 1024) == -1)
				ft_print_error(dir.parse.args[i]);
		}
		else
		{
			if (readlink(dir.trash = ft_strjoin_free(dir.path,
				dir.files[i], 0), buf, 1024) == -1)
				ft_print_error(dir.trash);
			ft_strdel(&(dir.trash));
		}
		ft_strcpy_at(line->line, buf, &line->pos, 1);
	}
}

void	opt_r2(t_dir *dir, int *dst_int)
{
	int i;

	dir ? free(dir->parse.type) : 0;
	dir ? dir->parse.type = ft_intdup(dst_int, dir->parse.nb_args) : 0;
	if (dir)
	{
		i = -1;
		while (++i < dir->parse.nb_args)
			dir->parse.type[i] = dst_int[i];
	}
	dir ? free(dst_int) : 0;
	dst_int = NULL;
}
