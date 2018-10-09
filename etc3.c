/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:20:41 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 11:37:10 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_digit(int x)
{
	int digit;

	digit = 0;
	while (x)
	{
		x /= 10;
		digit++;
	}
	if (!digit)
		return (1);
	return (digit);
}

char	*make_path(char *path, char *name)
{
	char	*new_path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_path = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(name) + 2));
	while (path[i] != '\0')
	{
		new_path[i] = path[i];
		i++;
	}
	new_path[i++] = '/';
	while (name[j] != '\0')
		new_path[i++] = name[j++];
	new_path[i] = '\0';
	return (new_path);
}

void	free_nodes(t_dirent *first)
{
	t_dirent *tmp;

	while (first != NULL)
	{
		tmp = first;
		first = first->next;
		free(tmp);
	}
}
