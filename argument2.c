/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:22:34 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 11:29:14 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirent	*reverse_order_arg(t_dirent *first)
{
	t_dirent *curr;
	t_dirent *prev;
	t_dirent *next;

	curr = first->next;
	prev = NULL;
	next = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	first->next = prev;
	return (first);
}

int			arg_time_cmp(t_dirent *x, t_dirent *y)
{
	struct stat x_stat;
	struct stat y_stat;

	lstat(x->d_name, &x_stat);
	lstat(y->d_name, &y_stat);
	if (x_stat.st_mtime > y_stat.st_mtime)
		return (0);
	else if (x_stat.st_mtime == y_stat.st_mtime)
	{
		if (x_stat.st_mtimespec.tv_nsec >= y_stat.st_mtimespec.tv_nsec)
			return (0);
	}
	return (1);
}

void		sort_in_time_arg(t_dirent *first, t_dirent *second)
{
	t_dirent *x;
	t_dirent *y;

	x = first;
	y = second;
	while (y->next != NULL)
	{
		if (arg_time_cmp(y, y->next))
		{
			x->next = y->next;
			y->next = (y->next)->next;
			(x->next)->next = y;
			x = first;
			y = x->next;
			continue;
		}
		x = x->next;
		y = y->next;
	}
}
