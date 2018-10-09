/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:29:55 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 11:30:28 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		delete_arg(t_dirent *before)
{
	t_dirent *target;

	target = before->next;
	before->next = target->next;
	free(target);
}

t_dirent	*arg_chck(t_dirent *first)
{
	t_dirent	*before;
	DIR			*dir;

	before = first;
	while (before->next)
	{
		dir = opendir(before->next->d_name);
		if (!dir)
		{
			if (errno != 20)
			{
				perror(before->next->d_name);
				delete_arg(before);
				continue;
			}
		}
		if (dir)
			closedir(dir);
		before = before->next;
	}
	return (first);
}

void		sort_arg(t_dirent *first, char *option)
{
	if (!check_option(option, 't') && !check_option(option, 'l'))
		sort_in_time_arg(first, first->next);
	if (!check_option(option, 'r'))
		reverse_order_arg(first);
}
