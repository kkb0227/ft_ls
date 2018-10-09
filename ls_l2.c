/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:12:27 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 14:57:57 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		without_r_hardlink_max(char *name, char *path, int max)
{
	struct stat	buff;
	char		*new_path;

	max = 1;
	new_path = make_path(path, name);
	lstat(path, &buff);
	if (max <= get_digit((int)buff.st_nlink))
		max = get_digit((int)buff.st_nlink);
	free(new_path);
	return (max);
}

int		without_r_size_max(char *name, char *path, int max)
{
	struct stat	buff;
	char		*new_path;

	new_path = make_path(path, name);
	lstat(new_path, &buff);
	if (max <= get_digit((int)buff.st_size))
		max = get_digit((int)buff.st_size);
	free(new_path);
	return (max);
}

int		total(char *name, char *path, int total_block)
{
	struct stat	buff;
	char		*new_path;

	new_path = make_path(path, name);
	lstat(new_path, &buff);
	total_block += buff.st_blocks;
	free(new_path);
	return (total_block);
}

void	print_link(int i, char *new_path, char buff[1024])
{
	i = readlink(new_path, buff, 1024);
	buff[i] = '\0';
	ft_printf(" -> %s", buff);
}

void	print_name_longformat(char *name, char *path, int info[3])
{
	char	buff[1024];
	int		i;
	char	*new_path;

	new_path = make_path(path, name);
	if (path[0] == '\0')
		longformat(name, info);
	else
		longformat(new_path, info);
	ft_printf(" %s", name);
	if (path[0] != '\0' && is_slink(new_path))
		print_link(i, new_path, buff);
	else
	{
		if (is_slink(name))
			print_link(i, name, buff);
	}
	ft_printf("\n");
	free(new_path);
}
