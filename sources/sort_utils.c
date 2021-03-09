/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lachille <lachille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 08:52:17 by gbikoumo          #+#    #+#             */
/*   Updated: 2020/03/07 12:26:53 by lachille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	merge2(char **arr, t_sort *vars, char **temp)
{
	while (vars->i <= vars->mid && vars->j <= vars->end)
	{
		if (ft_strcmp(arr[vars->i], arr[vars->j]) <= 0)
		{
			temp[vars->k] = ft_strdup(arr[vars->i]);
			vars->i++;
		}
		else
		{
			temp[vars->k] = ft_strdup(arr[vars->j]);
			vars->j++;
		}
		vars->k += 1;
	}
	while (vars->i <= vars->mid)
	{
		temp[vars->k] = ft_strdup(arr[vars->i]);
		vars->k += 1;
		vars->i += 1;
	}
}

void	mergedate2(char **arr, t_sort *vars, char **temp, t_dir *dircpy)
{
	while (vars->i <= vars->mid && vars->j <= vars->end)
	{
		if (lstat(vars->dir.trash = ft_strjoin_free(dircpy->path,
				arr[vars->i], 0), &(vars->dir.dstat)) < 0)
			ft_print_error(vars->dir.trash);
		if (lstat(vars->dir2.trash = ft_strjoin_free(dircpy->path,
				arr[vars->j], 0), &(vars->dir2.dstat)) < 0)
			ft_print_error(vars->dir2.trash);
		dircpy->path ? ft_strdel(&(vars->dir.trash)) : 0;
		dircpy->path ? ft_strdel(&(vars->dir2.trash)) : 0;
		if (vars->dir.dstat.st_mtime >= vars->dir2.dstat.st_mtime)
		{
			temp[vars->k] = ft_strdup(arr[vars->i]);
			vars->i++;
		}
		else
		{
			temp[vars->k] = ft_strdup(arr[vars->j]);
			vars->j++;
		}
		vars->k += 1;
	}
}
