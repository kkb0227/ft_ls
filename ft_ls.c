/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:20:05 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 17:16:11 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_option_large_r(t_dirent *first, int i, int argc, char *option)
{
	t_dirent	*tmp;

	tmp = first->next;
	while (tmp)
		tmp = ls_main(tmp, i, argc, option);
}

int		main(int argc, char **argv)
{
	int			i;
	char		option[5];
	t_dirent	*first;
	DIR			*dir;
	t_dirent	*tmp;

	i = option_manage(argc, argv, option);
	if (i == -1)
		return (0);
	if (argc == i)
		no_argument(option, argc, argv, i);
	else
	{
		first = before_ls(first, argc, argv, i);
		sort_arg(first, option);
		total_initial_print(first, option, argc, i);
		if (check_option(option, 'R'))
			print_directory(first, option, argc, i);
		else
			ls_option_large_r(first, i, argc, option);
		free_nodes(first);
	}
	return (0);
}
