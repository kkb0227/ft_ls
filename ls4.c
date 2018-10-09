/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:03:58 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 17:08:17 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_info(int info[3], t_dirent *tmp, char *path)
{
	info[0] = without_r_hardlink_max(tmp->d_name, path, info[0]);
	info[1] = without_r_size_max(tmp->d_name, path, info[1]);
	info[2] = total(tmp->d_name, path, info[2]);
}

void	get_info(int info[3], t_dirent *first, char *path, char *option)
{
	t_dirent *tmp;

	info[0] = 1;
	info[1] = 1;
	info[2] = 0;
	tmp = first->next;
	while (tmp)
	{
		if (!check_option(option, 'a'))
			put_info(info, tmp, path);
		else
		{
			if ((tmp->d_name)[0] != '.')
				put_info(info, tmp, path);
		}
		tmp = tmp->next;
	}
}

int		initial_print_with_l(t_dirent *first, char *option)
{
	t_dirent	*tmp;
	int			info[3];
	int			i;

	i = 0;
	tmp = first->next;
	get_info2(info, first, "", option);
	while (tmp)
	{
		if ((!check_option(option, 'a')) &&
		(is_file(tmp->d_name) || is_slink(tmp->d_name)))
		{
			print_name_longformat(tmp->d_name, "", info);
			i = 1;
		}
		else if (((tmp->d_name)[0] != '.') &&
		(is_file(tmp->d_name) || is_slink(tmp->d_name)))
		{
			print_name_longformat(tmp->d_name, "", info);
			i = 1;
		}
		tmp = tmp->next;
	}
	return (i);
}

void	get_info2(int info[3], t_dirent *first, char *path, char *option)
{
	t_dirent *tmp;

	info[0] = 1;
	info[1] = 1;
	info[2] = 0;
	tmp = first->next;
	while (tmp)
	{
		if (is_file(tmp->d_name) || is_slink(tmp->d_name))
		{
			if (!check_option(option, 'a'))
				put_info(info, tmp, path);
			else
			{
				if ((tmp->d_name)[0] != '.')
					put_info(info, tmp, path);
			}
		}
		tmp = tmp->next;
	}
}
