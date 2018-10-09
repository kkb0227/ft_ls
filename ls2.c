/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 14:43:45 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 14:11:01 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirent	*reverse_order(t_dirent *first)
{
	t_dirent *curr;
	t_dirent *prev;
	t_dirent *next;

	curr = first->next;
	prev = NULL;
	next = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	first->next = prev;
	return (first);
}

void		print_name(t_dirent *first, char *option)
{
	t_dirent *temp;

	temp = first->next;
	if (!check_option(option, 'a'))
	{
		while (temp)
		{
			ft_printf("%s\n", temp->d_name);
			temp = temp->next;
		}
	}
	else
	{
		while (temp)
		{
			if ((temp->d_name)[0] != '.')
				ft_printf("%s\n", temp->d_name);
			temp = temp->next;
		}
	}
}

int			option_a_initial_print(t_dirent *tmp, int i)
{
	if (is_file(tmp->d_name))
	{
		ft_printf("%s\n", tmp->d_name);
		i = 1;
	}
	return (i);
}

int			initial_print(t_dirent *first, char *option)
{
	t_dirent	*tmp;
	int			i;

	i = 0;
	tmp = first->next;
	while (tmp)
	{
		if (!check_option(option, 'a'))
			i = option_a_initial_print(tmp, i);
		else
		{
			if ((tmp->d_name)[0] != '.')
			{
				if (is_file(tmp->d_name))
				{
					ft_printf("%s\n", tmp->d_name);
					i = 1;
				}
			}
		}
		tmp = tmp->next;
	}
	return (i);
}
