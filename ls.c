/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:58:56 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 14:03:07 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_newnode(t_dirent *target, struct dirent *temp)
{
	t_dirent *newnode;

	newnode = malloc(sizeof(t_dirent));
	ft_strcpy(newnode->d_name, temp->d_name);
	newnode->next = target->next;
	target->next = newnode;
}

t_dirent	*make_list(char *dir)
{
	DIR				*directory;
	struct dirent	*temp;
	t_dirent		*start;

	start = malloc(sizeof(t_dirent));
	start->next = NULL;
	ft_strcpy(start->d_name, "start");
	directory = opendir(dir);
	temp = readdir(directory);
	while (temp)
	{
		add_newnode(start, temp);
		temp = readdir(directory);
	}
	sorting(start, start->next);
	closedir(directory);
	return (start);
}

void		sorting(t_dirent *start, t_dirent *second)
{
	t_dirent *x;
	t_dirent *y;

	x = start;
	y = second;
	while (y->next != NULL)
	{
		if (ft_strcmp(y->d_name, (y->next)->d_name) > 0)
		{
			x->next = y->next;
			y->next = (y->next)->next;
			(x->next)->next = y;
			x = start;
			y = x->next;
			continue;
		}
		x = x->next;
		y = (y->next);
	}
}

int			time_cmp(t_dirent *x, t_dirent *y, char *path)
{
	struct stat	x_stat;
	struct stat	y_stat;
	char		*new_path1;
	char		*new_path2;
	int			i;

	new_path1 = make_path(path, x->d_name);
	new_path2 = make_path(path, y->d_name);
	lstat(new_path1, &x_stat);
	lstat(new_path2, &y_stat);
	i = 1;
	if (x_stat.st_mtime > y_stat.st_mtime)
		i = 0;
	if (x_stat.st_mtime == y_stat.st_mtime)
	{
		if (x_stat.st_mtimespec.tv_nsec >= y_stat.st_mtimespec.tv_nsec)
			i = 0;
	}
	free(new_path1);
	free(new_path2);
	return (i);
}

void		sort_in_time(t_dirent *first, t_dirent *second, char *path)
{
	t_dirent *x;
	t_dirent *y;

	x = first;
	y = second;
	while (y->next != NULL)
	{
		if (time_cmp(y, y->next, path))
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
