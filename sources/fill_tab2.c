/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:57:04 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/07 11:54:18 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*fill_mode(struct stat *stat_file)
{
	char	*str;

	if (!(str = ft_strnew(11)))
		return (0);
	(S_ISREG(stat_file->st_mode) ? str[0] = '-' : 0);
	(S_ISDIR(stat_file->st_mode) ? str[0] = 'd' : 0);
	(S_ISCHR(stat_file->st_mode) ? str[0] = 'c' : 0);
	(S_ISBLK(stat_file->st_mode) ? str[0] = 'b' : 0);
	(S_ISFIFO(stat_file->st_mode) ? str[0] = 'f' : 0);
	(S_ISLNK(stat_file->st_mode) ? str[0] = 'l' : 0);
	(S_ISSOCK(stat_file->st_mode) ? str[0] = 's' : 0);
	str[1] = ((stat_file->st_mode & S_IRUSR) ? 'r' : '-');
	str[2] = ((stat_file->st_mode & S_IWUSR) ? 'w' : '-');
	str[3] = ((stat_file->st_mode & S_IXUSR) ? 'x' : '-');
	str[4] = ((stat_file->st_mode & S_IRGRP) ? 'r' : '-');
	str[5] = ((stat_file->st_mode & S_IWGRP) ? 'w' : '-');
	str[6] = ((stat_file->st_mode & S_IXGRP) ? 'x' : '-');
	str[7] = ((stat_file->st_mode & S_IROTH) ? 'r' : '-');
	str[8] = ((stat_file->st_mode & S_IWOTH) ? 'w' : '-');
	str[9] = ((stat_file->st_mode & S_IXOTH) ? 'x' : '-');
	(stat_file->st_mode & S_ISVTX) ? str[9] = 't' : 0;
	str[10] = ' ';
	return (str);
}

void		fill_tab_mode(t_dir dir, t_line *line, int i)
{
	if (!(line->mode[i] = fill_mode(&(dir.dstat))))
		exit(1);
	line->len_mode = 11;
}

void		fill_tab_link(t_dir dir, t_line *line, int i)
{
	int len2;

	len2 = 0;
	if (!(line->link[i] = ft_itoa(dir.dstat.st_nlink)))
		exit(1);
	len2 = ft_strlen(line->link[i]);
	if (line->len_link < len2)
		line->len_link = len2;
}

void		fill_tab_user(t_dir dir, t_line *line, int i)
{
	int				len2;
	struct passwd	*info_uid;

	len2 = 0;
	if (!(info_uid = getpwuid(dir.dstat.st_uid)))
		line->user[i] = ft_strnew(0);
	else if (!(line->user[i] = ft_strdup(info_uid->pw_name)))
		exit(1);
	len2 = ft_strlen(line->user[i]);
	if (line->len_user < len2)
		line->len_user = len2;
}

void		fill_tab_grp(t_dir dir, t_line *line, int i)
{
	int				len2;
	struct group	*info_gid;

	len2 = 0;
	if (!(info_gid = getgrgid(dir.dstat.st_gid)))
	{
		if (!(line->grp[i] = ft_strnew(0)))
			exit(1);
	}
	else if (!(line->grp[i] = ft_strdup(info_gid->gr_name)))
		exit(1);
	len2 = ft_strlen(line->grp[i]);
	if (line->len_grp < len2)
		line->len_grp = len2;
}
