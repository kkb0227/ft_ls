/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_large_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:02:18 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 14:41:23 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_large_r(char *dir, char *option, int argc, int i)
{
	t_dirent	*start;
	t_dirent	*tmp;
	char		*new_path;

	if (argc != i + 1 && argc != i)
		ft_printf("%s:\n", dir);
	start = ft_ls_without_large_r(dir, option);
	tmp = start->next;
	while (tmp)
	{
		new_path = make_path(dir, tmp->d_name);
		if (is_directory(new_path) &&
		!is_slink(new_path) && tmp->d_name[0] != '.')
		{
			ft_printf("\n");
			ft_ls_large_r(new_path, option, argc, 0);
		}
		free(new_path);
		tmp = tmp->next;
	}
	free_nodes(start);
}
