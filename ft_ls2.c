/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:31:48 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 15:52:58 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			option_manage(int ac, char **av, char *option)
{
	int i;

	i = 1;
	init_to_null(option);
	if (ac != 1)
		i = option_parsing(option, av, ac);
	return (i);
}

void		no_argument(char *option, int argc, char **argv, int i)
{
	t_dirent *first;

	if (!check_option(option, 'R'))
		ft_ls_large_r(".", option, argc, i);
	else
	{
		first = ft_ls_without_large_r(".", option);
		free_nodes(first);
	}
}

t_dirent	*before_ls(t_dirent *first, int argc, char **argv, int i)
{
	first = arguments(argc, argv, i);
	first = arg_chck(first);
	return (first);
}

t_dirent	*ls_main(t_dirent *tmp, int i, int argc, char *option)
{
	if (is_directory(tmp->d_name) && !is_slink(tmp->d_name))
	{
		ft_ls_large_r(tmp->d_name, option, argc, i);
		if (is_directory(tmp->next->d_name) && !is_slink(tmp->next->d_name))
			ft_printf("\n");
	}
	tmp = tmp->next;
	return (tmp);
}
