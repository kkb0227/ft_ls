/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:28:43 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 11:35:10 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_file(char *path)
{
	struct stat buff;

	if (!stat(path, &buff))
	{
		if (S_ISREG(buff.st_mode))
			return (1);
	}
	return (0);
}

int		is_slink(char *path)
{
	struct stat buff;

	if (!lstat(path, &buff))
	{
		if (S_ISLNK(buff.st_mode))
		{
			if (is_file(path))
				return (1);
			if (is_directory(path))
				return (2);
			return (3);
		}
	}
	return (0);
}

void	print_arg(t_dirent *first)
{
	t_dirent *tmp;

	tmp = first->next;
	while (tmp)
	{
		ft_printf("%s\n", tmp->d_name);
		tmp = tmp->next;
	}
}

void	print_file(t_dirent *first)
{
	t_dirent *tmp;

	tmp = first;
	while (tmp->next)
	{
		if (is_file(tmp->next->d_name))
		{
			ft_printf("%s\n", tmp->next->d_name);
			delete_arg(tmp);
			continue;
		}
		tmp = tmp->next;
	}
}
