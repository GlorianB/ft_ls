/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 09:40:04 by lachille          #+#    #+#             */
/*   Updated: 2020/03/07 09:21:46 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		opt_a(t_dir *dir)
{
	int		i;
	int		j;
	char	**dst;

	j = -1;
	i = -1;
	if (!(dst = malloc(sizeof(char *) * (dir->index + 1))))
		exit(1);
	while (++j <= dir->index)
	{
		if ((dir->flag & OPT_AMIN || (dir->flag & OPT_A
		&& ft_strcmp(dir->files[j], ".") && ft_strcmp(dir->files[j], ".."))
		|| *(dir->files)[j] != '.') && !(dst[++i] = ft_strdup(dir->files[j])))
			exit(1);
		ft_strdel(&(dir->files[j]));
	}
	free(dir->files);
	dir->index = i;
	dir->files = dst;
}

char		**opt_r(char **src, int index, t_dir *dir)
{
	char	**dst;
	int		*dst_int;
	int		i;

	i = -1;
	dst_int = NULL;
	if (!(dst = malloc(sizeof(char *) * (index + 1))))
		exit(1);
	if (dir)
		if (!(dst_int = (int*)malloc(sizeof(int) * index)))
			exit(1);
	while (--index >= 0)
	{
		if (!(dst[++i] = ft_strdup(src[index])))
			exit(1);
		if (dir)
			dst_int[i] = dir->parse.type[index];
		ft_strdel(&(src[index]));
	}
	free(src);
	opt_r2(dir, dst_int);
	return (dst);
}

char		*opt_h(char *str)
{
	int		len;
	char	*dst;
	int		i;
	int		nb_to_print;

	i = -1;
	len = ft_strlen(str);
	nb_to_print = len % 3;
	!nb_to_print ? nb_to_print = 3 : 0;
	if (!(dst = ft_strnew(4)))
		exit(1);
	while (++i < nb_to_print)
		dst[i] = str[i];
	if (nb_to_print == 1 && len > 1)
	{
		dst[i++] = '.';
		dst[i] = str[i - 1];
		i++;
	}
	free(str);
	if (!(dst[i] = assign_opt_h(len)))
		exit(1);
	i++;
	return (dst);
}

char		*opt_g(struct stat dstat)
{
	char *color;

	if (!(color = ft_strnew(9)))
		exit(1);
	S_ISREG(dstat.st_mode) ? color = ft_strcpy(color, "\e[0m") : 0;
	(dstat.st_mode & S_IXUSR) ? color = ft_strcpy(color, "\e[31m") : 0;
	S_ISCHR(dstat.st_mode) ? color = ft_strcpy(color, "\e[34;43m") : 0;
	S_ISDIR(dstat.st_mode) ? color = ft_strcpy(color, "\e[1;96m") : 0;
	S_ISLNK(dstat.st_mode) ? color = ft_strcpy(color, "\e[35m") : 0;
	S_ISBLK(dstat.st_mode) ? color = ft_strcpy(color, "\e[44m") : 0;
	S_ISSOCK(dstat.st_mode) ? color = ft_strcpy(color, "\e[32m") : 0;
	(dstat.st_mode & S_ISVTX) ? color = ft_strcpy(color, "\e[30;42m") : 0;
	return (color);
}
