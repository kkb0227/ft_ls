/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_id3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:01:33 by kykim             #+#    #+#             */
/*   Updated: 2018/07/31 18:20:49 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_p(int info[4], int buffsize, int digitvalue, intmax_t num)
{
	if (buffsize == digitvalue)
		buffsize = yes_p_digit(num, info, buffsize);
	else if (buffsize == info[2])
		buffsize = yes_p_precision(num, info, buffsize, digitvalue);
	else if (buffsize == info[1])
	{
		if ((info[0] % 1000) / 100 == 1)
			buffsize = yes_p_width(num, info, buffsize, digitvalue);
		else
			buffsize = yes_p_width2(num, info, buffsize, digitvalue);
	}
	return (buffsize);
}

int	convert_id(int info[4], va_list ap)
{
	intmax_t	num;
	int			digitvalue;
	int			buffsize;
	int			i;

	i = 0;
	num = length_convert_i(info, ap);
	digitvalue = digit(num);
	buffsize = bigger(info[1], bigger(info[2], digitvalue));
	if (info[2] == -1)
		return (no_precision(info, num));
	else if (info[2] == 0 && num == 0)
	{
		buffsize = info[1];
		while (i++ < buffsize)
			ft_putchar(' ');
		return (buffsize);
	}
	else if (info[2] != -1)
		buffsize = no_p(info, buffsize, digitvalue, num);
	return (buffsize);
}

int	convert_i_larged(int info[4], va_list ap)
{
	intmax_t	num;
	int			digitvalue;
	int			buffsize;
	int			i;

	i = 0;
	num = (long)va_arg(ap, intmax_t);
	digitvalue = digit(num);
	buffsize = bigger(info[1], bigger(info[2], digitvalue));
	if (info[2] == -1)
		return (no_precision(info, num));
	else if (info[2] == 0 && num == 0)
	{
		buffsize = info[1];
		while (i++ < buffsize)
			ft_putchar(' ');
		return (buffsize);
	}
	else if (info[2] != -1)
		buffsize = no_p(info, buffsize, digitvalue, num);
	return (buffsize);
}
