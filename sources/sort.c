/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbikoumo <gbikoumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 04:57:16 by lachille          #+#    #+#             */
/*   Updated: 2020/02/28 12:49:20 by gbikoumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	merge(char **arr, int start, int mid, int end)
{
	t_sort	vars;
	char	*temp[end - start + 1];

	vars.start = start;
	vars.mid = mid;
	vars.end = end;
	vars.i = start;
	vars.j = mid + 1;
	vars.k = 0;
	ft_bzero(&temp, end - start + 1);
	merge2(arr, &vars, temp);
	vars.i = start - 1;
	while (vars.j <= vars.end)
	{
		temp[vars.k] = ft_strdup(arr[vars.j]);
		vars.k += 1;
		vars.j += 1;
	}
	while (++vars.i <= end)
	{
		ft_strdel(&(arr[vars.i]));
		arr[vars.i] = ft_strdup(temp[vars.i - start]);
		free(temp[vars.i - start]);
	}
}

void		merge_sort(char **arr, int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

static void	mergedate(char **arr, t_sort vars, t_dir *dircpy)
{
	char	*temp[vars.end - vars.start + 1];

	vars.i = vars.start;
	vars.j = vars.mid + 1;
	vars.k = 0;
	mergedate2(arr, &vars, temp, dircpy);
	while (vars.i <= vars.mid)
	{
		temp[vars.k] = ft_strdup(arr[vars.i]);
		vars.k += 1;
		vars.i += 1;
	}
	while (vars.j <= vars.end)
	{
		temp[vars.k] = ft_strdup(arr[vars.j]);
		vars.k += 1;
		vars.j += 1;
	}
	vars.i = vars.start - 1;
	while (++vars.i <= vars.end)
	{
		ft_strdel(&(arr[vars.i]));
		arr[vars.i] = ft_strdup(temp[vars.i - vars.start]);
		free(temp[vars.i - vars.start]);
	}
}

void		opt_t(char **arr, int start, int end, t_dir *dircpy)
{
	t_sort vars;

	vars.start = start;
	vars.end = end;
	if (vars.start < vars.end)
	{
		vars.mid = (vars.start + vars.end) / 2;
		opt_t(arr, vars.start, vars.mid, dircpy);
		opt_t(arr, vars.mid + 1, vars.end, dircpy);
		if (!dircpy)
			exit(1);
		mergedate(arr, vars, dircpy);
	}
}
