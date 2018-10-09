/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:57:09 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 11:31:45 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	init_to_null(char *option)
{
	int i;

	i = 0;
	while (i < 5)
	{
		option[i] = 0;
		i++;
	}
}

int		is_directory(char *path)
{
	struct stat buff;

	if (!stat(path, &buff))
	{
		if (S_ISDIR(buff.st_mode))
			return (1);
	}
	return (0);
}
