/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:19:11 by kykim             #+#    #+#             */
/*   Updated: 2018/07/31 18:36:45 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_buff_same_width2(int info[4], int digit, uintmax_t num)
{
	int i;

	i = 0;
	if (((info[0] % 10000) / 1000) == 1)
	{
		while (i++ < info[1] - bigger(info[2], digit))
			ft_putchar('0');
		i = 0;
		while (i++ < info[2] - digit)
			ft_putchar('0');
	}
	else
	{
		while (i++ < info[1] - bigger(info[2], digit))
			ft_putchar(' ');
		i = 0;
		while (i++ < info[2] - digit)
			ft_putchar('0');
	}
	ft_putonly_unbr(num);
}

void	u_buff_same_width(int info[4], int digit, uintmax_t num)
{
	int i;

	i = 0;
	if ((info[0] % 1000) / 100 == 1)
	{
		while (i++ < info[2] - digit)
			ft_putchar('0');
		ft_putonly_unbr(num);
		i = 0;
		while (i++ < info[1] - bigger(info[2], digit))
			ft_putchar(' ');
	}
	else
		u_buff_same_width2(info, digit, num);
}

int		convert_u(int info[4], va_list ap)
{
	uintmax_t	num;
	int			digit;
	int			buffsize;

	num = length_convert_u(info, ap);
	digit = u_digit(num);
	buffsize = bigger(info[2], bigger(info[1], digit));
	if (buffsize == digit)
		ft_putonly_unbr(num);
	else if (buffsize == info[2])
	{
		putzero(info, digit);
		ft_putonly_unbr(num);
	}
	else if (buffsize == info[1])
		u_buff_same_width(info, digit, num);
	return (buffsize);
}

int		convert_largeu(int info[4], va_list ap)
{
	uintmax_t	num;
	int			digit;
	int			buffsize;

	num = (unsigned long)va_arg(ap, uintmax_t);
	digit = u_digit(num);
	buffsize = bigger(info[2], bigger(info[1], digit));
	if (buffsize == digit)
		ft_putonly_unbr(num);
	else if (buffsize == info[2])
	{
		putzero(info, digit);
		ft_putonly_unbr(num);
	}
	else if (buffsize == info[1])
		u_buff_same_width(info, digit, num);
	return (buffsize);
}
