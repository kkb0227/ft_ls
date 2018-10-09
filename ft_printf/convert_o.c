/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:29:10 by kykim             #+#    #+#             */
/*   Updated: 2018/08/01 21:16:22 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	same_oct_digit(int info[4], uintmax_t num, int digit)
{
	int buffsize;

	buffsize = digit;
	if ((info[0] / 10000) == 1)
	{
		ft_putstr("0");
		if (num == 0)
			return (1);
		buffsize += 1;
	}
	if (info[2] == 0)
	{
		if ((info[0] / 10000) == 1)
			return (1);
		return (0);
	}
	print_oct_o(num);
	return (buffsize);
}

int	same_oct_precision(int info[4], uintmax_t num, int digit)
{
	int buffsize;
	int i;

	i = 0;
	buffsize = info[2];
	while (i < info[2] - digit)
	{
		write(1, "0", 1);
		i++;
	}
	print_oct_o(num);
	return (buffsize);
}

int	same_oct_width(int info[4], uintmax_t num, int digit)
{
	int buffsize;
	int i;

	i = 0;
	if (info[2] == 0)
		return (no_p_octal(info));
	if ((info[0] / 10000) == 0)
		buffsize = width_without_hash_o(info, num, digit, i);
	else
	{
		if (info[1] - bigger(info[2], digit) < 1)
		{
			buffsize = info[1] + 1;
			if (info[2] < digit)
				ft_putstr("0");
			while (i++ < info[2] - digit)
				ft_putchar('0');
			print_oct_o(num);
		}
		else
			buffsize = width_with_hash_largew_o(info, num, digit, i);
	}
	return (buffsize);
}

int	convert_o(int info[4], va_list ap)
{
	uintmax_t	num;
	int			digit;
	int			buffsize;

	num = length_convert_o(info, ap);
	digit = oct_digit(num);
	buffsize = bigger(info[2], bigger(info[1], digit));
	if (info[2] != -1)
	{
		if (buffsize == digit)
			buffsize = same_oct_digit(info, num, digit);
		else if (buffsize == info[2])
			buffsize = same_oct_precision(info, num, digit);
		else if (buffsize == info[1])
			buffsize = same_oct_width(info, num, digit);
	}
	else
	{
		if (buffsize == digit)
			buffsize = same_oct_digit(info, num, digit);
		else if (buffsize == info[1])
			buffsize = same_oct_width_no_p(info, num, digit);
	}
	return (buffsize);
}

int	convert_largeo(int info[4], va_list ap)
{
	uintmax_t	num;
	int			digit;
	int			buffsize;

	num = (unsigned long)va_arg(ap, uintmax_t);
	digit = oct_digit(num);
	buffsize = bigger(info[2], bigger(info[1], digit));
	if (buffsize == digit)
		buffsize = same_oct_digit(info, num, digit);
	else if (buffsize == info[2])
		buffsize = same_oct_precision(info, num, digit);
	else if (buffsize == info[1])
		buffsize = same_oct_width(info, num, digit);
	return (buffsize);
}
