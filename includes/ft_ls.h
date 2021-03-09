/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:18:39 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/07 11:29:51 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/ioctl.h>
# include <dirent.h>
# include <stdio.h>
# include <stdbool.h>
# include <pwd.h>
# include <sys/types.h>
# include <sys/sysmacros.h>
# include <sys/stat.h>
# include <unistd.h>
# include <grp.h>
# include <stdio.h>
# include <time.h>
# include <sys/types.h>
# include <sys/errno.h>

# define OPT_L		1
# define OPT_R		2
# define OPT_AMIN	4
# define OPT_RMIN	8
# define OPT_T 		16
# define OPT_A		32
# define OPT_H		64
# define OPT_P		128
# define OPT_G		256

/*
**	'-a' ->  all => prend le dessus sur un -A
**	'-l' ->  line view
**	'-t' ->  Sort by time modified (most recently modified first)
**	'-r' ->  reverse sort
**	'-R' ->  recursive
**	'-A' ->  like a but without '.' & '..'
**	'-h' ->	 add suffix B,K,M,G,T,P   when use with -l  | Byte, Kilobyte,
**			Megabyte, Gigabyte, Terabyte and Petabyte
**	'-p' ->  add '/' at the end of filename if it's a directory
**	'-G' -> enable colors
*/

typedef struct		s_parse
{
	char			**args;
	char			**file;
	int				*type;
	int				nb_args;
	int				i;
}					t_parse;

/*
**	files = nom de fichier
**	index = nb max de fichier
**	flag = c'est les options
**	dstat = struc de la fonctioon stat et lstat
**	w = struct de ioctl => taille de l'ecran
**	info_uid => utilise dans ce programme pour le pw_name qui donne
**		le nom de l'utilisateur
**	directory = retour dew opendir
**	Pdirrent = retour de readdir
*/
typedef	struct		s_dir
{
	char			*path;
	char			**files;
	int				index;
	int				flag;
	struct stat		dstat;
	struct winsize	w;
	struct passwd	*info_uid;
	DIR				*directory;
	struct dirent	*pdirent;
	t_parse			parse;
	int				test_if_dir;
	int				test_files;
	char			*trash;
	int				mode;
}					t_dir;

/*
** struc utilise pour opt_t
*/
typedef	struct		s_sort
{
	int				start;
	int				mid;
	int				end;
	char			**arr;
	int				i;
	int				j;
	int				k;
	t_dir			dir;
	t_dir			dir2;
}					t_sort;

/*
** struc utilise pour l'option -l
*/
typedef	struct		s_line
{
	char			**mode;
	int				len_mode;
	char			**link;
	int				len_link;
	char			**user;
	int				len_user;
	char			**grp;
	int				len_grp;
	char			**size;
	int				len_size;
	char			**date;
	int				len_date;
	int				date_mode;
	unsigned int	pos;
	char			*line;
	int				total;
	unsigned int	alloc;
}					t_line;

/*
** struct utilise pour print classic
*/
typedef	struct		s_classic
{
	int				i;
	unsigned int	pos;
	int				nb_line;
	int				len;
	char			*line;
	int				mul;
}					t_classic;

typedef struct		s_fill
{
	int				len2;
	int				count_space;
	int				count_ddot;
	int				j;
	int				k;
	char			*tmp;
}					t_fill;

char				*opt_h(char *str);
char				**opt_r(char **src, int index, t_dir *dir);
void				opt_r2(t_dir *dir, int *dst_int);
void				opt_a(t_dir *dir);
char				*opt_g(struct stat stat_file);
void				merge2(char **arr, t_sort *vars, char **temp);
void				mergedate2(char **arr, t_sort *vars,
		char **temp, t_dir *dircpy);
void				merge_sort(char **arr, int start, int end);
void				opt_t(char **arr, int start, int end, t_dir *dircpy);
void				fill_tabs(t_dir dir, t_line *line, int i);
void				fill_tab_mode(t_dir dir, t_line *line, int i);
void				fill_tab_link(t_dir dir, t_line *line, int i);
void				fill_tab_user(t_dir dir, t_line *line, int i);
void				fill_tab_grp(t_dir dir, t_line *line, int i);
void				fill_tab_size(t_dir dir, t_line *line, int i);
void				fill_tab_date(t_dir dir, t_line *line, int i);
void				fill_line(int i, t_line *line);
void				fill_dir_files(t_dir *dir);
void				parse_args(t_dir *dir, char **av, int ac);
void				print_line(t_dir dir);
void				print_classic_solo_file(t_dir dir);
void				print_classic(t_dir dir);
void				print_symlink(t_dir dir, t_line *line, int i, int mode);
void				print_solo_file_line(t_dir dir);
void				print_line_without_joinfree(t_dir dir);
char				*add_space(int len, char *str);
void				ft_strcpy_at(char *str, char *str2,
		unsigned int *i, int mode);
int					alloc_tab_line_and_init_len(t_line *line, int len);
char				**realloc_line(char **old, unsigned int *buf);
void				print_tab(char **tab);
int					create_flag_mask(char *opt);
void				stat_or_lstat(t_dir *dir, int i);
int					assign_opt_h(int index);
int					*attribute_value(void);
void				free_args(t_dir *dir);
void				free_dir(t_dir *dir);
void				ft_print_error(char *arg1);
void				ft_print_without_slash(char *str);
void				ft_ls_args(t_dir *dir, char *path);
void				ft_ls(t_dir dir, char *path);
int					test_slash(char *str);

#endif
