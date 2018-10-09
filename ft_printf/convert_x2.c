/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:18:46 by kykim             #+#    #+#             */
/*   Updated: 2018/07/31 19:27:54 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_x2(int info[4], uintmax_t num, int digit, int buffsize)
{
	if (buffsize == digit)
		buffsize = same_hex_digit(info, num, digit);
	if (buffsize == info[1])
		buffsize = same_hex_width_0(info, num, digit);
	return (buffsize);
}

int	convert_x3(int info[4], uintmax_t num, int digit, int buffsize)
{
	if (buffsize == digit)
		buffsize = same_hex_digit(info, num, digit);
	else if (buffsize == info[2])
		buffsize = same_hex_precision(info, num, digit);
	else if (buffsize == info[1])
		buffsize = same_hex_width(info, num, digit);
	return (buffsize);
}

int	convert_x(int info[4], va_list ap)
{
	uintmax_t	num;
	int			digit;
	int			buffsize;

	num = length_convert_x(info, ap);
	digit = hex_digit(num);
	buffsize = bigger(info[2], bigger(info[1], digit));
	if (info[2] == 0 && num == 0 && info[1] == 0)
		return (0);
	if (info[2] == 0 && num == 0 && info[1] != 0)
	{
		while (info[1] > 0)
		{
			ft_putchar(' ');
			info[1]--;
		}
	}
	if ((info[2] == -1) && ((info[0] % 10000) / 1000 == 1))
		buffsize = convert_x2(info, num, digit, buffsize);
	else
		buffsize = convert_x3(info, num, digit, buffsize);
	return (buffsize);
}

int	convert_largex(int info[4], va_list ap)
{
	uintmax_t	num;
	int			digit;
	int			buffsize;

	num = length_convert_x(info, ap);
	digit = hex_digit(num);
	buffsize = bigger(info[2], bigger(info[1], digit));
	if (buffsize == digit)
		buffsize = same_hex_digit_l(info, num, digit);
	else if (buffsize == info[2])
		buffsize = same_hex_precision_l(info, num, digit);
	else if (buffsize == info[1])
		buffsize = same_hex_width_l(info, num, digit);
	return (buffsize);
}
