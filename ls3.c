/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 19:56:34 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 17:29:50 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	total_initial_print(t_dirent *first, char *option, int argc, int i)
{
	int			j;
	int			k;
	t_dirent	*tmp;

	tmp = first->next;
	j = 0;
	k = 0;
	if (!check_option(option, 'l'))
		k = initial_print_with_l(first, option);
	else
		k = initial_print(first, option);
	while (tmp)
	{
		if ((check_option(option, 'l') && (is_directory(tmp->d_name)))
		|| (is_directory(tmp->d_name) && !is_slink(tmp->d_name)))
			j = 1;
		tmp = tmp->next;
	}
	if (k && j)
		ft_printf("\n");
}

void	print_new_and_dirname(int last, int argc, t_dirent *tmp, int i)
{
	if (last)
		ft_printf("\n");
	if (argc != i + 1)
		ft_printf("%s:\n", tmp->d_name);
}

int		print_dir_l(char *option, t_dirent *tmp, int last)
{
	t_dirent	*start;

	start = ft_ls_without_large_r(tmp->d_name, option);
	free_nodes(start);
	last = 1;
	return (last);
}

void	print_directory(t_dirent *first, char *option, int argc, int i)
{
	t_dirent	*tmp;
	t_dirent	*start;
	int			last;

	last = 0;
	tmp = first->next;
	while (tmp)
	{
		if (check_option(option, 'l') && (is_directory(tmp->d_name)))
		{
			print_new_and_dirname(last, argc, tmp, i);
			last = print_dir_l(option, tmp, last);
		}
		else
		{
			if (is_directory(tmp->d_name) && !is_slink(tmp->d_name))
			{
				print_new_and_dirname(last, argc, tmp, i);
				last = print_dir_l(option, tmp, last);
			}
		}
		tmp = tmp->next;
	}
}
