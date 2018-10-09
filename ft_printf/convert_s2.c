/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 23:43:07 by kykim             #+#    #+#             */
/*   Updated: 2018/07/23 10:59:36 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	yes_flagw(int info[4], int buffsize, wchar_t *buff, wchar_t *str)
{
	int		i;

	i = 0;
	if (info[2] != -1)
	{
		while (i < smaller(buffsize, info[2]))
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

void	no_flagw(int info[4], int buffsize, wchar_t *buff, wchar_t *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (info[2] == -1)
	{
		while (i < buffsize - ft_wstrlen(str))
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

int		convert_s2(int info[4], va_list ap)
{
	wchar_t	*buff;
	int		buffsize;
	wchar_t	*str;
	int		i;

	i = 0;
	str = va_arg(ap, wchar_t *);
	buffsize = setbuffsize(info, ft_wstrlen(str));
	buff = (wchar_t *)malloc(sizeof(wchar_t) * (buffsize + 1));
	buff[buffsize] = '\0';
	if (((info[0] % 1000) / 100) == 1)
		yes_flagw(info, buffsize, buff, str);
	else
		no_flagw(info, buffsize, buff, str);
	ft_putwstr(buff);
	free(buff);
	return (buffsize);
}

int		convert_s_total(int info[4], va_list ap)
{
	if (info[3] == 4)
		return (convert_s2(info, ap));
	else
		return (convert_s(info, ap));
}
