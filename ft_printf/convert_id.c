/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:05:23 by kykim             #+#    #+#             */
/*   Updated: 2018/07/31 18:14:01 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_precision(int info[4], intmax_t num)
{
	int buffsize;
	int digitvalue;
	int i;
	int j;

	j = 0;
	i = 0;
	digitvalue = digit(num);
	buffsize = bigger(info[1], bigger(info[2], digitvalue));
	if (buffsize == digitvalue)
		buffsize = no_p_digit(num, info, buffsize);
	else if (buffsize == info[1])
	{
		if ((info[0] % 1000) / 100 == 1)
			buffsize = no_p_width(num, info, buffsize, digitvalue);
		else
		{
			if ((info[0] % 10000) / 1000 == 1)
				buffsize = no_p_width2(num, info, digitvalue);
			else
				buffsize = no_p_width3(num, info, digitvalue);
		}
	}
	return (buffsize);
}

int	yes_p_digit(intmax_t num, int info[4], int buffsize)
{
	if (num < 0)
		ft_putchar('-');
	if ((info[0] % 100) / 10 == 1 && num >= 0)
	{
		ft_putchar('+');
		buffsize++;
	}
	else if ((info[0] % 10) == 1 && num >= 0)
	{
		ft_putchar(' ');
		buffsize++;
	}
	printrealnum(num);
	return (buffsize);
}

int	yes_p_precision(intmax_t num, int info[4], int buffsize, int digitvalue)
{
	int i;

	i = 0;
	if ((info[0] % 100) / 10 == 1 && num >= 0)
	{
		ft_putchar('+');
		buffsize++;
	}
	else if ((info[0] % 10) == 1 && num >= 0)
	{
		ft_putchar(' ');
		buffsize++;
	}
	if (num < 0)
	{
		ft_putchar('-');
		buffsize++;
	}
	while (i < info[2] - digitvalue)
	{
		ft_putchar('0');
		i++;
	}
	printrealnum(num);
	return (buffsize);
}

int	yes_p_width(intmax_t num, int info[4], int buffsize, int digitvalue)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (num < 0 || ((info[0] % 100) / 10 == 1 && num >= 0) ||
	((info[0] % 10) == 1 && num >= 0))
	{
		if (num < 0)
			ft_putchar('-');
		else if (((info[0] % 100) / 10 == 1 && num >= 0))
			ft_putchar('+');
		else if (((info[0] % 10) == 1 && num >= 0))
			ft_putchar(' ');
		j = 1;
	}
	while (i++ < info[2] - digitvalue)
		ft_putchar('0');
	printrealnum(num);
	i = 0;
	while (i++ < buffsize - bigger(digitvalue, info[2]) - j)
		ft_putchar(' ');
	return (buffsize);
}

int	yes_p_width2(intmax_t num, int info[4], int buffsize, int digitvalue)
{
	int i;

	i = 0;
	if (num < 0 || ((info[0] % 100) / 10 == 1 && num >= 0) ||
	((info[0] % 10) == 1 && num >= 0))
		i++;
	while (i < buffsize - bigger(info[2], digitvalue))
	{
		ft_putchar(' ');
		i++;
	}
	if (num < 0)
		ft_putchar('-');
	else if (((info[0] % 100) / 10 == 1 && num >= 0))
		ft_putchar('+');
	else if (((info[0] % 10) == 1 && num >= 0))
		ft_putchar(' ');
	i = 0;
	while (i++ < info[2] - digitvalue)
		ft_putchar('0');
	printrealnum(num);
	return (buffsize);
}
