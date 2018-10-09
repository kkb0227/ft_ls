/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:01:28 by kykim             #+#    #+#             */
/*   Updated: 2018/07/26 13:35:39 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		setbuffsize(int info[4], int strlen)
{
	int buffsize;

	buffsize = 0;
	if (info[1] >= strlen && info[1] >= info[2])
		buffsize = info[1];
	else if (strlen >= info[1] && strlen >= info[2])
	{
		if (info[2] == -1)
			buffsize = strlen;
		else if (info[2] != -1)
			buffsize = bigger(info[1], info[2]);
	}
	else if (info[2] >= info[1] && info[2] >= strlen)
		buffsize = bigger(info[1], strlen);
	return (buffsize);
}

void	yes_flag(int info[4], int buffsize, char *buff, char *str)
{
	int i;

	i = 0;
	if (info[2] != -1)
	{
		while (i < smaller(ft_strlen(str), info[2]))
		{
			buff[i] = str[i];
			i++;
		}
	}
	else
		while (str[i] != '\0')
		{
			buff[i] = str[i];
			i++;
		}
	while (i < buffsize)
	{
		buff[i] = ' ';
		i++;
	}
}

void	no_flag(int info[4], int buffsize, char *buff, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < buffsize - ft_strlen(str))
		buff[i++] = ' ';
	if (info[2] == -1)
	{
		while (i < buffsize - ft_strlen(str))
			buff[i++] = ' ';
	}
	else
	{
		while (i < buffsize - info[2])
			buff[i++] = ' ';
	}
	while (i < buffsize)
	{
		buff[i] = str[j];
		i++;
		j++;
	}
}

int		convert_s(int info[4], va_list ap)
{
	char	*buff;
	int		buffsize;
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	buffsize = setbuffsize(info, ft_strlen(str));
	buff = (char *)malloc(sizeof(char) * (buffsize + 1));
	buff[buffsize] = '\0';
	if (((info[0] % 1000) / 100) == 1)
		yes_flag(info, buffsize, buff, str);
	else
		no_flag(info, buffsize, buff, str);
	ft_putstr(buff);
	free(buff);
	return (buffsize);
}
