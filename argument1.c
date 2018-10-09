/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:24:38 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 11:21:30 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		argument_sort(t_dirent *first, t_dirent *second)
{
	t_dirent *x;
	t_dirent *y;

	x = first;
	y = second;
	while (y->next != NULL)
	{
		if (ft_strcmp(y->d_name, (y->next)->d_name) > 0)
		{
			x->next = y->next;
			y->next = (y->next)->next;
			(x->next)->next = y;
			x = first;
			y = x->next;
			continue;
		}
		x = x->next;
		y = (y->next);
	}
}

void		add_argument_node(t_dirent *target, char *name)
{
	t_dirent *new;

	new = malloc(sizeof(t_dirent));
	ft_strcpy(new->d_name, name);
	new->next = target->next;
	target->next = new;
}

t_dirent	*make_arguments_list(int argc, char **argv, t_dirent *first, int i)
{
	while (i < argc)
	{
		add_argument_node(first, argv[i]);
		i++;
	}
	return (first);
}

t_dirent	*arguments(int argc, char **argv, int i)
{
	t_dirent *first;

	first = malloc(sizeof(t_dirent));
	ft_strcpy(first->d_name, "");
	first->next = NULL;
	first = make_arguments_list(argc, argv, first, i);
	argument_sort(first, first->next);
	return (first);
}
