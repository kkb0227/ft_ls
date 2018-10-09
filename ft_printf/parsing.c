/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:03:34 by kykim             #+#    #+#             */
/*   Updated: 2018/07/18 23:01:34 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flagcheck(const char *str, int i, int info[4])
{
	int num;

	num = 0;
	while (str[i] == '#' || str[i] == '0' || str[i] == '-' ||
			str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '#' && (num / 10000) == 0)
			num += 10000;
		else if (str[i] == '0' && ((num % 10000) / 1000) == 0)
			num += 1000;
		else if (str[i] == '-' && ((num % 1000) / 100) == 0)
			num += 100;
		else if (str[i] == '+' && ((num % 100) / 10 == 0))
			num += 10;
		else if (str[i] == ' ' && (num % 10) == 0)
			num += 1;
		else
			num += 0;
		i++;
	}
	info[0] = num;
	return (i);
}

int	widthcheck(const char *str, int i, int info[4], va_list ap)
{
	int total;

	total = 0;
	if (str[i] == '*')
	{
		total = va_arg(ap, int);
		i++;
	}
	else
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			total = (total * 10) + str[i] - 48;
			i++;
		}
	}
	info[1] = total;
	return (i);
}

int	precisioncheck(const char *str, int i, int info[4], va_list ap)
{
	int total;

	total = -1;
	if (str[i] == '.')
	{
		total = 0;
		i++;
		if (str[i] == '*')
		{
			total = va_arg(ap, int);
			i++;
		}
		else
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				total = (total * 10) + str[i] - 48;
				i++;
			}
		}
	}
	info[2] = total;
	return (i);
}

int	lengthcheck(const char *str, int i, int info[4])
{
	if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
			info[3] = 1;
		else
			info[3] = 2;
	}
	else if (str[i] == 'l')
	{
		if (str[i + 1] == 'l')
			info[3] = 3;
		else
			info[3] = 4;
	}
	else if (str[i] == 'j')
		info[3] = 5;
	else if (str[i] == 'z')
		info[3] = 6;
	else
		info[3] = 0;
	if (info[3] == 1 || info[3] == 3)
		return (i + 2);
	if (info[3] == 2 || (info[3] >= 4 && info[3] <= 6))
		return (i + 1);
	return (i);
}

int	allcheck(const char *str, int i, int info[4], va_list ap)
{
	i = flagcheck(str, i + 1, info);
	i = widthcheck(str, i, info, ap);
	i = precisioncheck(str, i, info, ap);
	i = lengthcheck(str, i, info);
	return (i);
}
