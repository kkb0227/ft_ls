/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_without_large_r.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:51:36 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 14:40:41 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirent		*ft_ls_without_large_r(char *dir, char *option)
{
	t_dirent	*start;
	t_dirent	*tmp;
	int			info[3];

	start = make_list(dir);
	if (!check_option(option, 't'))
		sort_in_time(start, start->next, dir);
	if (!check_option(option, 'r'))
		reverse_order(start);
	if (!check_option(option, 'l'))
	{
		get_info(info, start, dir, option);
		tmp = start->next;
		if (tmp->next->next || !check_option(option, 'a'))
			ft_printf("total %d\n", info[2]);
		printing(tmp, option, dir, info);
	}
	else
		print_name(start, option);
	return (start);
}

void			printing(t_dirent *tmp, char *option, char *dir, int info[3])
{
	while (tmp)
	{
		if (!check_option(option, 'a'))
			print_name_longformat(tmp->d_name, dir, info);
		else
		{
			if ((tmp->d_name)[0] != '.')
				print_name_longformat(tmp->d_name, dir, info);
		}
		tmp = tmp->next;
	}
}
